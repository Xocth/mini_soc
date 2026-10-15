# Mini SOC — Host-Based Security Monitoring Dashboard

A lightweight, SOC-style security monitoring tool built as a learning project.
A C++ backend collects and serves security events; a Svelte frontend (in progress)
will visualise them as an analyst dashboard.

> **Status:** work in progress — backend MVP running, frontend setup pending.

## Architecture

```text
Browser  (Svelte dashboard, port 5173)
   |  /api/*  (Vite dev proxy)
   v
C++ backend  (cpp-httplib, 127.0.0.1:8081)
   |
   v
Event sources  (demo JSON now -> JSONL logs / SQLite / inotify later)
```

## Repository Layout

```text
mini_soc/
├── backend/
│   ├── src/main.cpp             # C++ HTTP API (cpp-httplib + nlohmann/json)
│   ├── third_party/
│   │   ├── httplib.h            # header-only HTTP server
│   │   └── nlohmann/json.hpp    # header-only JSON library (v3.11.3)
│   └── CMakeLists.txt
├── frontend/                    # Svelte + Vite app (setup pending)
├── logs/                        # future: JSONL event sources
├── data/                        # future: SQLite database
└── README.md
```

## Prerequisites

- WSL2 + Debian (or any modern Linux)
- `build-essential`, `cmake`, `pkg-config`, `git`, `curl`
- Node.js >= 20.19 via `nvm` (frontend only)

## Backend — Build & Run

```bash
cmake -S backend -B build/backend -DCMAKE_BUILD_TYPE=Debug
cmake --build build/backend -j
./build/backend/mini_soc_backend
```

The API binds to **127.0.0.1:8081** only. (Port 8080 is occupied on this host by an
unrelated service, so 8081 was chosen deliberately.)

### Endpoints

| Method | Path         | Description                  |
|--------|--------------|------------------------------|
| GET    | `/api/status`| Service health check         |
| GET    | `/api/events`| Current security event list  |

Example response:

```json
{
  "events": [
    { "id": 1, "severity": "low",  "source": "demo", "message": "Test security event" },
    { "id": 2, "severity": "high", "source": "auth", "message": "Multiple failed login attempts detected" }
  ]
}
```

## Frontend — Setup (Next Step)

```bash
npm create vite@latest frontend -- --template svelte
cd frontend && npm install
# In vite.config.js: proxy '/api' -> http://127.0.0.1:8081
npm run dev    # dashboard at http://localhost:5173
```

## Security Notes

- Backend listens on loopback only; **no authentication yet** — never expose to LAN/internet.
- Third-party dependencies are header-only and fetched explicitly (cpp-httplib, nlohmann/json v3.11.3).
- Runs unprivileged; no root required for the MVP.


## Roadmap

- [x] C++ HTTP API serving demo events
- [ ] Svelte dashboard (status card, events table, severity badges)
- [ ] Ingest real events from JSONL log files
- [ ] SQLite persistence
- [ ] Detection rules (e.g. failed-login threshold per IP)
- [ ] Live updates (polling → WebSocket/SSE)
- [ ] Host telemetry: `/proc/net/tcp` listener watchdog + inotify file integrity

## Course Relevance

Hands-on practice for cybersecurity topics: secure software development in C++,
operating systems (processes, sockets, `/proc`), networking (HTTP, ports, same-origin
policy), and defensive security / SOC operations (log analysis, detection, alerting).

