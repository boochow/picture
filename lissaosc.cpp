/*
 * File: lissaosc.cpp
 */

#include "userosc.h"

#include "figure.h"

#define BUFSIZE (VERTICES*4)

static q31_t wavetable[BUFSIZE];

typedef struct State {
    float w0;
    float phase;
    uint8_t flags;
} State;

static State s_state;

enum {
    k_flags_none = 0,
    k_flag_reset = 1<<0,
};

static void init_wavetable(void) {
    q31_t x, y;
    for(int i = 0; i < VERTICES; i++) {
        x = f32_to_q31(figure_x[i] / 2);
        y = f32_to_q31(figure_y[i] / 2 + 0.5);
        wavetable[i]                = y;
        wavetable[i + VERTICES]     = 0x7fffffff - x;
        wavetable[i + 2 * VERTICES] = 0x7fffffff - y;
        wavetable[i + 3 * VERTICES] = x;
    }
}

void OSC_INIT(uint32_t platform, uint32_t api)
{
    s_state.w0    = 0.f;
    s_state.phase = 0.f;
    s_state.flags = k_flags_none;
    init_wavetable();
}

void OSC_CYCLE(const user_osc_param_t * const params,
               int32_t *yn,
               const uint32_t frames)
{
    const uint8_t flags = s_state.flags;
    s_state.flags = k_flags_none;

    const float w0 = s_state.w0 = osc_w0f_for_note((params->pitch)>>8, params->pitch & 0xFF);
    float phase = (flags & k_flag_reset) ? 0.f : s_state.phase;
  
    q31_t * __restrict y = (q31_t *) yn;
    const q31_t * y_e = y + frames;

    for (; y != y_e; ) {
        const float pos = phase * BUFSIZE;
        uint32_t idx = (uint32_t) pos;
        const float frac = pos - idx;
        const float m = q31_to_f32(wavetable[idx++]);
        const float n = q31_to_f32(wavetable[(idx == BUFSIZE) ? 0 : idx]);
        const float sig = linintf(frac, m, n);
        *(y++) = f32_to_q31(sig);
        phase += w0;
        phase -= (uint32_t) phase;
    }
    s_state.phase = phase;
}

void OSC_NOTEON(const user_osc_param_t * const params)
{
    s_state.flags |= k_flag_reset;
}

void OSC_NOTEOFF(const user_osc_param_t * const params)
{
}

void OSC_PARAM(uint16_t index, uint16_t value)
{
    const float valf = param_val_to_f32(value);
    switch (index) {
    case k_user_osc_param_id1:
    case k_user_osc_param_id2:
    case k_user_osc_param_id3:
    case k_user_osc_param_id4:
    case k_user_osc_param_id5:
    case k_user_osc_param_id6:
    case k_user_osc_param_shape:
    case k_user_osc_param_shiftshape:
    default:
        break;
  }
}
