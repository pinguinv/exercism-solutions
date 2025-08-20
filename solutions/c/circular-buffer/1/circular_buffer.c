#include "circular_buffer.h"

#include <stdio.h>

static size_t empty_index = 0, oldest_index = 0;

circular_buffer_t *new_circular_buffer(size_t capacity)
{
    circular_buffer_t *buffer = (circular_buffer_t *)malloc(sizeof(circular_buffer_t));

    buffer->capacity = capacity;
    buffer->values = (buffer_value_t *)calloc(capacity, sizeof(buffer_value_t));

    return buffer;
}

void clear_buffer(circular_buffer_t *buffer)
{
    for (size_t i = 0; i < buffer->capacity; i++)
    {
        buffer->values[i] = 0;
    }

    empty_index = 0;
    oldest_index = 0;
}

void delete_buffer(circular_buffer_t *buffer)
{
    empty_index = 0;
    oldest_index = 0;

    free(buffer->values);
    free(buffer);
}

int16_t write(circular_buffer_t *buffer, buffer_value_t value)
{
    if (empty_index == buffer->capacity)
    {
        errno = ENOBUFS;
        return EXIT_FAILURE;
    }

    buffer->values[empty_index] = value;

    empty_index = (empty_index + 1) % buffer->capacity;

    empty_index = buffer->values[empty_index] == 0
                      ? empty_index
                      : buffer->capacity;

    return EXIT_SUCCESS;
}

int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value)
{
    if (empty_index == buffer->capacity)
    {
        buffer_value_t read_value;
        read(buffer, &read_value);
    }

    write(buffer, value);

    return EXIT_SUCCESS;
}

int16_t read(circular_buffer_t *buffer, buffer_value_t *read_value)
{
    if (buffer->capacity == 0 || buffer->values[oldest_index] == 0)
    {
        errno = ENODATA;
        return EXIT_FAILURE;
    }

    *read_value = buffer->values[oldest_index];
    buffer->values[oldest_index] = 0;

    empty_index = empty_index == buffer->capacity
                      ? oldest_index
                      : empty_index;

    oldest_index = (oldest_index + 1) % buffer->capacity;

    return EXIT_SUCCESS;
}