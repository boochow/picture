#define VERTICES 32
#define WAVETABLES 4

static float figure_x[WAVETABLES][VERTICES] = {
    {
        0.82,
        0.82,
        0.61,
        0.43,
        0.4,
        0.25,
        0.05,
        0.25,
        0.05,
        0.25,
        0.4,
        0.4,
        0.475,
        0.625,
        0.7,
        0.625,
        0.55,
        0.6,
        0.6,
        0.55,
        0.475,
        0.4,
        0.45,
        0.45,
        0.4,
        0.4,
        0.5,
        0.56,
        0.61,
        0.66,
        0.72,
        0.82,
    },
    {
    0.9,
    0.82,
    0.61,
    0.4,
    0.25,
    0.0,
    0.25,
    0.0,
    0.25,
    0.4,
    0.4,
    0.4,
    0.475,
    0.625,
    0.7,
    0.625,
    0.55,
    0.6,
    0.6,
    0.55,
    0.475,
    0.4,
    0.45,
    0.45,
    0.38,
    0.4,
    0.5,
    0.53,
    0.61,
    0.69,
    0.72,
    0.82,
    },
    {
        0.89,
        0.89,
        0.68,
        0.47,
        0.25,
        0.47,
        0.25,
        0.02,
        0.02,
        0.25,
        0.47,
        0.47,
        0.61,
        0.61,
        0.63,
        0.59,
        0.61,
        0.61,
        0.75,
        0.75,
        0.77,
        0.73,
        0.75,
        0.75,
        0.89,
        0.68,
        0.47,
        0.47,
        0.59,
        0.68,
        0.77,
        0.89,
    },
    {
        0.99,
        0.5,
        0.3960441546,
        0.2966316785,
        0.2061073739,
        0.1284275873,
        0.06698729811,
        0.02447174185,
        0.002739052316,
        0.002739052316,
        0.02447174185,
        0.06698729811,
        0.1284275873,
        0.2061073739,
        0.2966316785,
        0.3960441546,
        0.5,
        0.6039558454,
        0.7033683215,
        0.7938926261,
        0.8715724127,
        0.9330127019,
        0.7165063509,
        0.5,
        0.7165063509,
        0.9330127019,
        0.8715724127,
        0.7938926261,
        0.7033683215,
        0.6039558454,
        0.2,
        0.99,
    }
};

static float figure_y[WAVETABLES][VERTICES] = {
    {
        0.23,
        0.66,
        0.77,
        0.69,
        0.34,
        0.23,
        0.3,
        0.5,
        0.7,
        0.77,
        0.66,
        0.53,
        0.615,
        0.445,
        0.53,
        0.615,
        0.53,
        0.495,
        0.555,
        0.53,
        0.445,
        0.53,
        0.495,
        0.555,
        0.53,
        0.23,
        0.33,
        0.23,
        0.33,
        0.23,
        0.33,
        0.23,
    },
    {
    0.20,
    0.66,
    0.77,
    0.58,
    0.77,
    0.6,
    0.5,
    0.4,
    0.23,
    0.34,
    0.66,
    0.50,
    0.615,
    0.445,
    0.53,
    0.615,
    0.53,
    0.495,
    0.555,
    0.53,
    0.445,
    0.53,
    0.495,
    0.555,
    0.52,
    0.23,
    0.33,
    0.23,
    0.33,
    0.23,
    0.33,
    0.23,
    },
    {
        0.23,
        0.66,
        0.77,
        0.66,
        0.5,
        0.34,
        0.23,
        0.34,
        0.66,
        0.77,
        0.66,
        0.35,
        0.47,
        0.51,
        0.55,
        0.55,
        0.51,
        0.47,
        0.47,
        0.51,
        0.55,
        0.55,
        0.51,
        0.47,
        0.4,
        0.45,
        0.45,
        0.23,
        0.3,
        0.23,
        0.3,
        0.23,
    },
    {
        0.0,
        0.0,
        0.01092619963,
        0.04322727118,
        0.09549150281,
        0.1654346968,
        0.25,
        0.3454915028,
        0.4477357684,
        0.5522642316,
        0.6545084972,
        0.75,
        0.8345653032,
        0.9045084972,
        0.9567727288,
        0.9890738004,
        1,
        0.9890738004,
        0.9567727288,
        0.9045084972,
        0.8345653032,
        0.75,
        0.625,
        0.5,
        0.375,
        0.25,
        0.2254346968,
        0.19549150281,
        0.14322727118,
        0.11092619963,
        0.1,
        0,
    }
};
