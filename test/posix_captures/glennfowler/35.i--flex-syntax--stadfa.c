/* Generated by re2c */

{
	YYCTYPE yych;
	if ((YYLIMIT - YYCURSOR) < 4) YYFILL(4);
	yych = *(YYMARKER = YYCURSOR);
	switch (yych) {
	case 'a':	goto yy3;
	default:	goto yy2;
	}
yy2:
	yynmatch = 1;
	yypmatch[0] = YYCURSOR;
	yypmatch[1] = YYCURSOR;
	{}
yy3:
	yych = *++YYCURSOR;
	yyt8 = YYCURSOR - 1;
	switch (yych) {
	case 'a':	goto yy5;
	case 'b':	goto yy7;
	default:	goto yy4;
	}
yy4:
	YYCURSOR = YYMARKER;
	goto yy2;
yy5:
	yych = *++YYCURSOR;
	yyt1 = yyt7 = NULL;
	yyt2 = YYCURSOR - 1;
	switch (yych) {
	case 'b':	goto yy8;
	default:
		yyt5 = yyt6 = NULL;
		yyt4 = yyt2;
		yyt3 = yyt1;
		yyt2 = yyt7;
		yyt1 = yyt8;
		goto yy6;
	}
yy6:
	yynmatch = 5;
	yypmatch[2] = yyt1;
	yypmatch[4] = yyt2;
	yypmatch[5] = yyt3;
	yypmatch[6] = yyt4;
	yypmatch[8] = yyt5;
	yypmatch[9] = yyt6;
	yypmatch[0] = yyt1;
	yypmatch[1] = YYCURSOR;
	yypmatch[3] = yyt4;
	yypmatch[7] = YYCURSOR;
	{}
yy7:
	yych = *++YYCURSOR;
	yyt7 = YYCURSOR - 1;
	switch (yych) {
	case 'a':	goto yy9;
	default:	goto yy4;
	}
yy8:
	++YYCURSOR;
	yyt5 = YYCURSOR - 1;
	yyt6 = YYCURSOR;
	yyt4 = yyt2;
	yyt3 = yyt1;
	yyt2 = yyt7;
	yyt1 = yyt8;
	goto yy6;
yy9:
	yych = *++YYCURSOR;
	yyt1 = yyt2 = YYCURSOR - 1;
	switch (yych) {
	case 'b':	goto yy8;
	default:
		yyt5 = yyt6 = NULL;
		yyt4 = yyt2;
		yyt3 = yyt1;
		yyt2 = yyt7;
		yyt1 = yyt8;
		goto yy6;
	}
}

posix_captures/glennfowler/35.i--flex-syntax--stadfa.re:6:7: warning: rule matches empty string [-Wmatch-empty-string]