#include "circular_buffer.h"

circular_buffer_t *new_circular_buffer(size_t capacity)
{
    circular_buffer_t *buffer = (circular_buffer_t *)malloc(sizeof(circular_buffer_t));

    buffer->capacity = capacity;

    buffer->count = 0;
    buffer->head = 0;
    buffer->tail = 0;

    buffer->values = (buffer_value_t *)calloc(capacity, sizeof(buffer_value_t));

    return buffer;
}

void clear_buffer(circular_buffer_t *buffer)
{
    buffer->head = 0;
    buffer->tail = 0;
    buffer->count = 0;
}

void delete_buffer(circular_buffer_t *buffer)
{
    free(buffer->values);
    free(buffer);
}

int16_t write(circular_buffer_t *buffer, buffer_value_t value)
{
    if (buffer->count == buffer->capacity)
    {
        errno = ENOBUFS;
        return EXIT_FAILURE;
    }

    buffer->values[buffer->head] = value;

    buffer->head = (buffer->head + 1) % buffer->capacity;

    buffer->count++;

    return EXIT_SUCCESS;
}

int16_t read(circular_buffer_t *buffer, buffer_value_t *read_value)
{
    if (!buffer->count)
    {
        errno = ENODATA;
        return EXIT_FAILURE;
    }

    *read_value = buffer->values[buffer->tail];

    buffer->tail = (buffer->tail + 1) % buffer->capacity;

    buffer->count--;

    return EXIT_SUCCESS;
}

int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value)
{
    if (buffer->count == buffer->capacity)
    {
        buffer_value_t read_value;
        read(buffer, &read_value);
    }

    write(buffer, value);

    return EXIT_SUCCESS;
}