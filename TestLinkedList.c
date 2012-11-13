#include "CuTest.h"

#include "LinkedList.h"


void TestInitLL(CuTest *tc) {
    LinkedList *ll = initLL();
    CuAssertPtrEquals(tc, ll->head, NULL);
}


void TestLengthLL(CuTest *tc) {
    LinkedList *ll = initLL();
    CuAssertIntEquals(tc, 0, lengthLL(ll));
}


void TestInsertLLIncreasesLength(CuTest *tc) {
    LinkedList *ll = initLL();
    insertLL(ll, (void *) 1, 0);
    CuAssertIntEquals(tc, 1, lengthLL(ll));
}

void TestInsertLLInserts(CuTest *tc) {
    LinkedList *ll = initLL();
    insertLL(ll, (void *) 1, 0);
    CuAssertIntEquals(tc, 1, countLL(ll, (void *) 1));
}

void TestCountLL(CuTest *tc) {
    LinkedList *ll = initLL();
    insertLL(ll, (void *) 1, 0);
    insertLL(ll, (void *) 1, 0);
    CuAssertIntEquals(tc, 2, countLL(ll, (void *) 1));
}


void TestIndexLL(CuTest *tc) {
    LinkedList *ll = initLL();
    insertLL(ll, (void *) 1, 0);
    insertLL(ll, (void *) 2, 0);
    CuAssertIntEquals(tc, 0, indexLL(ll, (void *) 2));
}


void TestRemoveLL(CuTest *tc) {
    LinkedList *ll = initLL();
    insertLL(ll, (void *) 1, 0);
    insertLL(ll, (void *) 2, 0);
    removeLL(ll, (void *) 2);
    CuAssertIntEquals(tc, 1, lengthLL(ll));
}


void TestExtendLL(CuTest *tc) {
    LinkedList *ll = initLL();
    LinkedList *ll2 = initLL();
    insertLL(ll, (void *) 1, 0);
    insertLL(ll2, (void *) 2, 0);
    extendLL(ll, ll2);
    CuAssertIntEquals(tc, 2, lengthLL(ll));
}


void TestLookup(CuTest *tc) {
    LinkedList *ll = initLL();
    insertLL(ll, (void *) 1, 0);
    insertLL(ll, (void *) 2, 0);
    CuAssertIntEquals(tc, 1, (int) (long) lookupLL(ll, 1));
}


void TestLookup2(CuTest *tc) {
    LinkedList *ll = initLL();
    insertLL(ll, (void *) "ab", 0);
    insertLL(ll, (void *) "cd", 0);
    CuAssertStrEquals(tc, "ab", (char*) lookupLL(ll, 1));
}

void TestLookup3(CuTest *tc) {
    LinkedList *ll = initLL();
    LinkedList *ll2 = initLL();
    insertLL(ll, ll2, 0);
    CuAssertPtrEquals(tc, ll2, (LinkedList*) lookupLL(ll, 0));
}
