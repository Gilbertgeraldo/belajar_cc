"""
Script untuk menguji ketahanan backend sendiri.
HANYA dipakai untuk testing backend milik sendiri, dengan izin sendiri.

Cara pakai:
    pip install httpx --break-system-packages
    python backend_stress_test.py --base-url https://port-be-phi.vercel.app
"""

import asyncio
import argparse
import time
import httpx
from collections import Counter


async def test_rate_limit_login(base_url: str, attempts: int = 15):
    """
    Simulasi percobaan login berkali-kali secara cepat, untuk cek
    apakah rate limiting di endpoint /auth/login benar-benar aktif.
    Kalau rate limiting bekerja, seharusnya setelah beberapa percobaan
    gagal, backend mulai balas dengan status 429 (Too Many Requests).
    """
    print(f"\n=== Test Rate Limit: POST {base_url}/api/v1/auth/login ===")
    url = f"{base_url}/api/v1/auth/login"
    payload = {"email": "bukan-akun-asli@test.com", "password": "salah-sengaja"}

    status_counter = Counter()
    async with httpx.AsyncClient(timeout=10) as client:
        for i in range(1, attempts + 1):
            try:
                resp = await client.post(url, json=payload)
                status_counter[resp.status_code] += 1
                tag = "429 (DIBLOKIR)" if resp.status_code == 429 else resp.status_code
                print(f"  Percobaan {i:>2}: status {tag}")
            except httpx.RequestError as e:
                print(f"  Percobaan {i:>2}: gagal connect ({e})")
            await asyncio.sleep(0.2)  # jeda kecil antar request

    print("\nRingkasan status code:", dict(status_counter))
    if 429 in status_counter:
        print("✅ Rate limiting AKTIF — backend mulai menolak setelah beberapa percobaan.")
    else:
        print("⚠️  Rate limiting TIDAK terdeteksi — backend menerima semua percobaan tanpa dibatasi.")


async def test_public_endpoint_load(base_url: str, path: str, concurrent: int = 20):
    """
    Kirim beberapa request bersamaan (concurrent) ke endpoint publik,
    untuk lihat bagaimana response time-nya di bawah beban ringan.
    """
    print(f"\n=== Test Load: GET {base_url}{path} ({concurrent} request bersamaan) ===")
    url = f"{base_url}{path}"

    async def single_request(client, idx):
        start = time.perf_counter()
        try:
            resp = await client.get(url)
            elapsed = (time.perf_counter() - start) * 1000
            return resp.status_code, elapsed
        except httpx.RequestError as e:
            return "ERROR", str(e)

    async with httpx.AsyncClient(timeout=15) as client:
        tasks = [single_request(client, i) for i in range(concurrent)]
        results = await asyncio.gather(*tasks)

    ok = [r for r in results if r[0] == 200]
    failed = [r for r in results if r[0] != 200]

    if ok:
        times = [r[1] for r in ok]
        print(f"  Berhasil : {len(ok)}/{concurrent}")
        print(f"  Waktu rata-rata : {sum(times)/len(times):.1f} ms")
        print(f"  Waktu tercepat  : {min(times):.1f} ms")
        print(f"  Waktu terlambat : {max(times):.1f} ms")
    if failed:
        print(f"  Gagal    : {len(failed)}/{concurrent} -> {failed[:5]}")


async def main():
    parser = argparse.ArgumentParser(description="Stress test backend sendiri")
    parser.add_argument("--base-url", required=True, help="Contoh: https://port-be-phi.vercel.app")
    parser.add_argument("--login-attempts", type=int, default=15)
    parser.add_argument("--concurrent", type=int, default=20)
    args = parser.parse_args()

    base_url = args.base_url.rstrip("/")

    await test_rate_limit_login(base_url, attempts=args.login_attempts)
    await test_public_endpoint_load(base_url, "/api/v1/projects", concurrent=args.concurrent)
    await test_public_endpoint_load(base_url, "/api/v1/skills", concurrent=args.concurrent)

    print("\nSelesai. Naikkan --login-attempts atau --concurrent kalau mau tes lebih berat.")


if __name__ == "__main__":
    asyncio.run(main())