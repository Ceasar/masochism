

/* This is auto-generated code. Edit at your own peril. */
#include <stdio.h>
#include <stdlib.h>

#include "CuTest.h"


extern void TestInitLL(CuTest*);
extern void TestLengthLL(CuTest*);
extern void TestInsertLLIncreasesLength(CuTest*);
extern void TestInsertLLInserts(CuTest*);
extern void TestCountLL(CuTest*);
extern void TestIndexLL(CuTest*);
extern void TestRemoveLL(CuTest*);
extern void TestExtendLL(CuTest*);
extern void TestLookup(CuTest*);
extern void TestLookup2(CuTest*);
extern void TestLookup3(CuTest*);


void RunAllTests(void) 
{
    CuString *output = CuStringNew();
    CuSuite* suite = CuSuiteNew();


    SUITE_ADD_TEST(suite, TestInitLL);
    SUITE_ADD_TEST(suite, TestLengthLL);
    SUITE_ADD_TEST(suite, TestInsertLLIncreasesLength);
    SUITE_ADD_TEST(suite, TestInsertLLInserts);
    SUITE_ADD_TEST(suite, TestCountLL);
    SUITE_ADD_TEST(suite, TestIndexLL);
    SUITE_ADD_TEST(suite, TestRemoveLL);
    SUITE_ADD_TEST(suite, TestExtendLL);
    SUITE_ADD_TEST(suite, TestLookup);
    SUITE_ADD_TEST(suite, TestLookup2);
    SUITE_ADD_TEST(suite, TestLookup3);

    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
    CuStringDelete(output);
    CuSuiteDelete(suite);
}

int main(void)
{
    RunAllTests();
}

