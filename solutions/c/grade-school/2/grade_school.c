#include "grade_school.h"

static size_t find_new_student_index(roster_t *roster_ptr, student_t *student_ptr)
{
    size_t student_index = 0;

    while (roster_ptr->students[student_index].grade != 0 && student_ptr->grade > roster_ptr->students[student_index].grade)
        student_index++;

    int first_in_same_grade = -1;

    if (roster_ptr->students[student_index].grade == student_ptr->grade)
        first_in_same_grade = student_index;

    if (first_in_same_grade == -1)
        return student_index;

    int last_in_same_grade = first_in_same_grade;

    while (roster_ptr->students[last_in_same_grade].grade == student_ptr->grade)
        last_in_same_grade++;

    while ((int)student_index < last_in_same_grade)
    {
        if (strcmp(student_ptr->name, roster_ptr->students[student_index].name) < 0)
            break;

        student_index++;
    }

    return student_index;
}

static bool insert_student(roster_t *roster_ptr, student_t *student_ptr, size_t index)
{
    if (roster_ptr->count >= MAX_STUDENTS)
        return false;

    // move students after `index` to the right
    for (size_t i = roster_ptr->count; i > index; i--)
        roster_ptr->students[i] = roster_ptr->students[i - 1];

    roster_ptr->students[index] = *student_ptr;
    roster_ptr->count++;

    return true;
}

void init_roster(roster_t *roster_ptr)
{
    roster_ptr->count = 0;
    memset(roster_ptr->students, 0, sizeof(student_t) * MAX_STUDENTS);
}

bool add_student(roster_t *roster_ptr, char *name, uint8_t grade)
{
    for (size_t i = 0; i < roster_ptr->count; i++)
        if (strcmp(roster_ptr->students[i].name, name) == 0)
            return false;

    student_t new_student;
    new_student.grade = grade;
    strcpy(new_student.name, name);

    size_t new_student_index = find_new_student_index(roster_ptr, &new_student);
    insert_student(roster_ptr, &new_student, new_student_index);

    return true;
}

roster_t get_grade(roster_t *roster_ptr, uint8_t desired_grade)
{
    roster_t grade_roster;
    init_roster(&grade_roster);

    for (size_t i = 0, j = 0; i < roster_ptr->count; i++)
        if (roster_ptr->students[i].grade == desired_grade)
        {
            grade_roster.count++;
            grade_roster.students[j++] = roster_ptr->students[i];
        }

    return grade_roster;
}