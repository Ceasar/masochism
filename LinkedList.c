#include "LinkedList.h"

// Private

typedef struct Link {
    void *data;
    struct Link *next;
} Link;

// Assume *data has been allocated
Link *makeLink(void *data) {
    Link *link;
    link = (Link *) malloc(sizeof(Link));
    link->data = data;
    link->next = NULL;
    return link;
}

// Public

LinkedList *initLL() {
    LinkedList *ll;
    ll = (LinkedList *) malloc(sizeof(LinkedList));
    ll->_size = 0;
    ll->head = NULL;
    return ll;
}

int countLL(const LinkedList *ll, void *data) {
    int count = 0;
    Link *link;
    link = ll->head;
    while (link != NULL) {
        if (link->data == data) {
            count++;
        }

        link = link->next;
    }
    return count;
}

void extendLL(LinkedList *ll, const LinkedList *ll2) {
    int i = 0;
    int n = lengthLL(ll2);
    for (i = 0; i < n; i++) {
        insertLL(ll, lookupLL(ll2, i), 0);
    }
}

int indexLL(const LinkedList *ll, void *data) {
    int index = 0;
    Link *link;
    link = ll->head;
    while (link != NULL) {
        if (link->data == data) {
            return index;
        }

        link = link->next;
        index++;
    }
    return -1;
}

int insertLL(LinkedList *ll, void *data, int i) {
    int index = 0;
    Link *newLink;
    newLink = makeLink(data);

    Link *link, *prev;
    prev = NULL;
    link = ll->head;
    if (link == NULL) {
        ll->head = newLink;
        ll->_size++;
        return 0;
    }
    while (link != NULL) {
        if (index == i) {
            if (prev == NULL) {
                ll->head = newLink;
            } else {
                prev->next = newLink;
            }
            newLink->next = link;
            ll->_size++;
            return 0;
        }

        prev = link;
        link = link->next;
        index++;
    }
    return -1;
}

int lengthLL(const LinkedList *ll) {
    return ll->_size;
}

void *lookupLL(const LinkedList *ll, int i) {
    int index = 0;
    Link *link;
    link = ll->head;
    if (link == NULL) {
        return NULL;
    }
    while (link != NULL) {
        if (index == i) {
            return link->data;
        }

        link = link->next;
        index++;
    }
    return NULL;
}

int popLL(LinkedList *ll, int i) {
    int index = 0;
    Link *link, *prev;
    prev = NULL;
    link = ll->head;
    if (link == NULL) {
        return -1;
    }
    while (link != NULL) {
        if (index == i) {
            if (prev == NULL) {
                ll->head = link->next;
            } else {
                prev->next = link->next;
            }
            free(link);
            ll->_size--;
            return 0;
        }

        prev = link;
        link = link->next;
        index++;
    }
    return -1;
}

int removeLL(LinkedList *ll, void *data) {
    return popLL(ll, indexLL(ll, data));
}

void showLL(const LinkedList *ll) {
    printf("[");

    Link *link;
    link = ll->head;
    while (link != NULL) {
        // This is kind of arbitrary
        printf("%d", (int) (long) link->data);

        link = link->next;
        if (link != NULL) {
            printf(", ");
        }
    }

    printf("]\n");
}
