/* See LICENSE file for copyright and license details. */



/* appearance */
static const char font[]            = "Clean";//"-*-terminus-medium-r-*-*-16-*-*-*-*-*-*-*";
static const char normbordercolor[] = "#444444";
static const char normbgcolor[]     = "#4d4b47";
static const char normfgcolor[]     = "#efeae1";
static const char selbordercolor[]  = "#4a9701";
static const char selbgcolor[]      = "#efeae1";
static const char selfgcolor[]      = "#4a9701";
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */

/* tagging */
static const char *tags[] = { "dev", "wat", "fun", "nop", "snd", "idk" };

static const Rule rules[] = {
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "pavucontrol",  NULL,       NULL,       4,       False,       -1 },
};

/* layout(s) */
static const float mfact      = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster      = 1;    /* number of clients in master area */
static const Bool resizehints = True; /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[T]",      tile },    /* first entry is default */
	{ "[F]",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define WINKEY Mod4Mask
#define ALTKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ ALTKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ WINKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ WINKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ WINKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = { "dmenu_run", "-fn", font, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "tilda", NULL };
/* Print Screen */
char buff[29];
static const char *prsncmd[] = { "maim", "/home/erik/screenshots/screenshot.png", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
    { 0,                            XK_Print,  spawn,          {.v = prsncmd } },
    { WINKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ WINKEY,                       XK_Return, spawn,          {.v = dmenucmd } },
	{ WINKEY|ShiftMask,             XK_t,      spawn,          {.v = termcmd } },
	{ WINKEY,                       XK_b,      togglebar,      {0} },
	{ ALTKEY,                       XK_Tab,    focusstack,     {.i = +1 } },
	{ ALTKEY|ShiftMask,             XK_Tab,    focusstack,     {.i = -1 } },
//	{ WINKEY,                       XK_i,      incnmaster,     {.i = +1 } },
//	{ WINKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ WINKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ WINKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ WINKEY,                       XK_Up,     zoom,           {0} },
//	{ WINKEY,                       XK_J,      view,           {0} },
	{ ALTKEY,                       XK_q,      killclient,     {0} },
	{ WINKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ WINKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ WINKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
//	{ WINKEY,                       XK_p,      setlayout,      {0} },
	{ WINKEY|ShiftMask,             XK_Return, togglefloating, {0} },
	{ WINKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ WINKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ WINKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ WINKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ WINKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ WINKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ WINKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         WINKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         WINKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         WINKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            WINKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            WINKEY,         Button3,        toggletag,      {0} },
};

