#ifndef FILL_DATE_STRUCT_H
#define FILL_DATE_STRUCT_H

struct date {
    int day;
    int month;
    int year;
};

struct date FillDate(long second);

#endif // FILL_DATE_STRUCT_H