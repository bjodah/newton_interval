#ifndef _UNITTEST_H_
#define _UNITTEST_H_

typedef int (*TestFunc)();

typedef struct testcase_t {
  TestFunc func;
  char* name;
} TestCase;

int run_tests(int ntests, const TestCase** test_cases, char * suite_name);

#endif
