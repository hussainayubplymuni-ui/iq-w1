# LHPK4014 Software Engineering 1 – W1 Set Exercises

Personalization Number: **4827**

One C++ program with ten short exercises, each in its own function (`task1()` to `task10()`).

## Files

| File | What it is |
|------|------------|
| `4827_C1.cpp` | Final version to submit |
| `iqw1.cpp` | Version 1, my first attempt (kept to show my working) |
| `iqw1version2.cpp` | Version 2, my corrected version |
| `tests/run_tests.sh` | Builds the program and checks its output |
| `.github/workflows/build.yml` | GitHub Actions: runs the tests on every push |

## Build and run

```
g++ -std=c++17 -Wall -Wextra 4827_C1.cpp -o app
./app
```

Only Task 9 reads input: type marks one per line, and `-1` to stop.

## Continuous integration

Every push runs `tests/run_tests.sh` on GitHub Actions. A red ✗ means the build or a test failed;
a green ✓ means everything passed. The commit history shows Version 1 failing, then each error
being fixed one commit at a time until the checks pass.

## Version history

1. Version 1 copied into `4827_C1.cpp` – **fails**: local variables hid the global `personalizationNum` (compile error with `-Wshadow -Werror`).
2. Fix Error 3 (shadowing) – **fails**: Tasks 1 and 2 read input they did not need, so they used up the Task 9 marks.
3. Fix Errors 1 and 2 (fixed values from 4827) – **fails**: Task 9 got stuck in an endless loop when a letter was typed.
4. Fix Error 5 (Task 9 input check) – **fails**: output text did not match (spacing and typos).
5. Fix Errors 6–8 (prototype, output text, header comments) – **passes**.
6. Task 7 name changed to "Student 4827" so no real name is in the code (anonymous marking) – **passes**.
