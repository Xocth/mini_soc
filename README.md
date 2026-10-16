# Mini SOC — Host-Based Security Monitoring Dashboard

- A lightweight, SOC-style security monitoring tool built as a learning project.
- A C++ backend collects and serves security events.
- Deciding how to do Dashboard frotend probably with Vanilla JS right now.


## Backend — Build & Run

```bash
cmake -S backend -B build/backend -DCMAKE_BUILD_TYPE=Debug
cmake --build build/backend -j
./build/backend/mini_soc_backend
```

or use CMake extension for ease of use

## Roadmap

- [x] C++ HTTP 
- [ ] Dashboard (status card, events table, severity badges)
- [ ] Ingest real events from JSONL log files
- [ ] ?SQL?SQLite?


## Course Relevance

Hands-on practice for cybersecurity topics: secure software development in C++,
operating systems, networking (HTTP, ports, same-origin
policy), and defensive security / SOC operations (log analysis, detection, alerting).

