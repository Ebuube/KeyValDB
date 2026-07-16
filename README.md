# KeyValDB

A key-value store database implemented in C, built from the ground up on a custom hashtable.

KeyValDB is a learning-and-build project: the goal is to implement a working key-value store (think a tiny Redis-like engine) starting from core data structures and building outward toward persistence and configurable database behavior.

## Status

🚧 **Early development.** The hashtable itself hasn't been built yet — the current focus is implementing and testing the singly linked list that will back each hashtable bucket (for collision resolution via chaining).

Implemented so far:
- [x] Singly linked list (`list_t`) with key/value string pairs and operations
- [ ] Hashtable
- [ ] Persistence layer
- [ ] Database operations (get/set/delete API)
- [ ] Configurability

## Project Structure

```
.
├── include
│   └── linked_list
│       └── lists.h          # list_t struct + function declarations
├── src
│   └── linked_list
│       ├── add_node.c
│       ├── del_node.c
│       ├── find_node.c
│       ├── free_list.c
│       ├── print_list.c
│       └── update_node.c
├── test
│   ├── linked_list
│   │   └── test_add_node.c  # Unity/Ceedling test cases
│   └── support
├── project.yml               # Ceedling project configuration
└── build/                     # Ceedling build output (generated, git-ignored)
```

As the hashtable and other components are added, they'll live alongside `linked_list/` under their own subdirectories in `include/`, `src/`, and `test/`.

## Prerequisites

- GCC and standard build tools (`build-essential` on Debian/Ubuntu)
- Ruby (Ceedling is Ruby-based)
- [Ceedling](https://www.throwtherules.com/ceedling/) — install via:
  ```bash
  gem install ceedling
  ```

This project is developed inside a Vagrant VM (`ubuntu-focal`); using Vagrant is optional but mirrors the dev environment this was built and tested in.

## Getting Started

Clone the repo:

```bash
git clone https://github.com/Ebuube/KeyValDB.git
cd KeyValDB
```

If you're using Vagrant, spin up and SSH into the box first, then run the clone/setup steps inside it.

## Running Tests

This project uses [Ceedling](https://www.throwtherules.com/ceedling/) (with Unity and CMock) for unit testing.

Run the full test suite:

```bash
ceedling test:all
```

Run a single test file:

```bash
ceedling test:test_add_node
```

Test source files live under `test/linked_list/`. Since multiple `.c` files in `src/linked_list/` share a single header (`lists.h`), each test file explicitly declares which source file(s) it needs via `TEST_SOURCE_FILE(...)`, e.g.:

```c
TEST_SOURCE_FILE("src/linked_list/add_node.c")
```

New test files should add their own `TEST_SOURCE_FILE` line(s) for whichever functions they exercise.

## Roadmap

1. **Linked list** — finish `find_node`, `del_node`, `update_node`, `free_list`, `print_list`, with full test coverage for each.
2. **Hashtable** — build the hashtable on top of the linked list, using chaining for collision resolution.
3. **Persistence** — durable storage so data survives restarts (e.g. write-ahead log or snapshotting to disk).
4. **Database operations** — a proper get/set/delete API layer on top of the hashtable.
5. **Configurability** — tunable settings (e.g. table size, persistence strategy, eviction policy).

## License

To Be Determined.
