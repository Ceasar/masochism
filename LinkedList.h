#include <stdlib.h>
#include <stdio.h>

/*
 * Generic LinkedList class.
 * Supports regular operations for appending and remove items to a list.
 *
 * On account of being generic, the LinkedList requires constant casting to and
 * from `void *`.
 */
typedef struct LinkedList {
    struct Link *head;
    int _size;
} LinkedList;


/*
 * Initialize an empty LinkedList.
 * @return Pointer to LinkedList
 */
LinkedList *initLL();


/*
 * Count all elements equal to data.
 * @param item to count
 * @return number of equal items
 */
int countLL(const LinkedList *ll, void *data);


/*
 * Concatenate two lists.
 * @param list to modify
 * @param list to copy from
 */
void extendLL(LinkedList *ll, const LinkedList *ll2);


/*
 * Get the first index of `data` or -1.
 * @param LinkedList to search
 * @return item to find
 */
int indexLL(const LinkedList *ll, void *data);


/*
 * Insert an item at index i. Return -1 on error.
 * @param LinkedList to insert into
 * @return 0 on success, else -1
 */
int insertLL(LinkedList *ll, void *data, int i);


/*
 * Get the length of the list
 * @param LinkedList to measure
 */
int lengthLL(const LinkedList *ll);


/*
 * Get the item at index `i`
 * @param LinkedList to search
 * @param Index of item
 * @return (void *) pointer to item
 */
void *lookupLL(const LinkedList *ll, int i);


/*
 * Remove the item at index `i`
 * @param LinkedList to search
 * @param Index of item to remove
 * @return 0 on success, -1 on failure
 */
int popLL(LinkedList *ll, int i);


/*
 * Remove the item equal to `data`
 * @param LinkedList to search
 * @param item to remove
 * @return 0 on success, -1 on failure
 */
int removeLL(LinkedList *ll, void *data);


/*
 * Print a linked list as a list of integers
 * @param LinkedList to show
 */
void showLL(const LinkedList *ll);
