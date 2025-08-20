#include "high_scores.h"

int32_t latest(const int32_t *scores, size_t scores_len)
{
    if (scores_len < 1)
        return 0;

    return scores[scores_len - 1];
}

int32_t personal_best(const int32_t *scores, size_t scores_len)
{
    int32_t best = 0;
    for (int i = 0; i < (int)scores_len; i++)
        best = scores[i] > best ? scores[i] : best;

    return best;
}

size_t personal_top_three(const int32_t *scores, size_t scores_len,
                          int32_t *output)
{
    // copy scores arr
    int32_t scores_copy[scores_len];
    for (int i = 0; i < (int)scores_len; i++)
        scores_copy[i] = scores[i];

    int output_len = (int)scores_len < 3 ? (int)scores_len : 3;

    for (int i = 0; i < output_len; i++)
    {
        int32_t best_i = 0;

        // find top score
        for (int j = 0; j < (int)scores_len; j++)
        {
            if (scores_copy[j] > best_i)
                best_i = scores_copy[j];
        }

        // zero found top score
        for (int j = 0; j < (int)scores_len; j++)
        {
            if (scores_copy[j] == best_i)
            {
                scores_copy[j] = 0;
                break;
            }
        }

        // write found top to output
        output[i] = best_i;
    }

    return output_len;
}
