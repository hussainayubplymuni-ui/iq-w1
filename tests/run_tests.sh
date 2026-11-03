#!/usr/bin/env bash
# Builds the W1 program and checks its output against the brief.
# A failing step makes the GitHub Actions run show a red X.
set -u
SRC="${1:-4827_C1.cpp}"
fail=0

echo "== Build (warnings are treated as errors)"
if ! g++ -std=c++17 -Wall -Wextra -Wshadow -Werror "$SRC" -o app; then
  echo "BUILD FAILED"; exit 1
fi

check() {  # name, input, expected text
  out=$(printf -- "$2" | timeout 5 ./app 2>&1); code=$?
  if [ $code -eq 124 ]; then echo "FAIL: $1 (program got stuck, timed out)"; fail=1; return; fi
  if grep -qF -- "$3" <<<"$out"; then echo "PASS: $1"; else echo "FAIL: $1 (expected: $3)"; fail=1; fi
}

echo "== Tests"
check "Task 1 sum of 8 and 7"            '80\n70\n-1\n'   'Sum : 15'
check "Task 2 21 x 5"                    '80\n70\n-1\n'   'Result = 105'
check "Task 4 4827 is odd"               '80\n70\n-1\n'   '4827 is odd'
check "Task 5 month is April"            '80\n70\n-1\n'   'April'
check "Task 6 third value is 7"          '80\n70\n-1\n'   'Third value = 7'
check "Task 8 called 5 times"            '80\n70\n-1\n'   'Total function count is 5'
check "Task 9 average of 80 and 70"      '80\n70\n-1\n'   'average of the marks is : 75'
check "Task 9 negative marks ignored"    '50\n-5\n100\n-1\n' 'average of the marks is : 75'
check "Task 9 no valid marks gives 0"    '-1\n'           'average of the marks is : 0'
check "Task 9 letter typed by mistake"   'abc\n60\n-1\n'  'average of the marks is : 60'
check "Task 10 local resets to 4828"     '80\n70\n-1\n'   'Local: 4828'

exit $fail
