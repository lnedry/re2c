/* Generated by re2c */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>
#include <assert.h>

#define YYMAXFILL 19

static const size_t SIZE = 4096;

struct input_t {
  char buf[SIZE + YYMAXFILL];
  char *lim;
  char *cur;
  char *tok;
  char *mark;
  int state;
  unsigned yyaccept;
  char yych;
  FILE *file;

  input_t(FILE * file)
    : buf()
    , lim(buf + SIZE)
    , cur(lim)
    , tok(lim)
    , mark(lim)
    , state(0)
    , yyaccept(0)
    , yych(0)
    , file(file)
  {}

  bool fill()
  {
    const size_t free = (tok - buf) + SIZE - (lim - buf);
    if (free < 1) return false;
    const size_t prefix = (tok - buf);

    memmove(buf, tok, buf - tok + SIZE);
    lim -= prefix;
    cur -= prefix;
    tok -= prefix;
    mark -= prefix;
    size_t to_read = SIZE - (lim - buf);
    printf("> Reading input, can take up to %lu bytes\n", to_read);
    size_t bytes_read = fread(lim, 1, to_read, file);
    lim += bytes_read;
    lim[0] = 0;

    // quick make a copy of buffer with newlines replaced w/ _
    char b[40];
    snprintf(b, 40, "%s", buf);
    for(int i = 0; i < 40; i++) {
      if ('\n' == b[i]) { b[i] = '_'; }
    }
    printf("> Read %lu bytes from input, current buffer: >%.40s<\n", bytes_read, b);

    return true;
  }
};

enum status_t {
  OK,
  FAIL,
  NEED_MORE_INPUT,
  WHITESPACE,
  WORD,
  THING
};
const char * STATUSES[] = {
  "OK",
  "FAIL",
  "NEED_MORE_INPUT",
  "WHITESPACE",
  "WORD",
  "THING"
};

#define YYGETSTATE()  in.state
#define YYSETSTATE(s) in.state = s
#define YYFILL() do { \
  printf("< Returning for more input\n"); \
  return NEED_MORE_INPUT; \
} while (0)

static status_t lex(input_t &in)
{
switch (YYGETSTATE()) {
default: goto yy0;
case 0: if (in.lim <= in.cur) goto yyeof0; goto yyFillLabel0;
case 1: if (in.lim <= in.cur) goto yyeof1; goto yyFillLabel1;
case 2: if (in.lim <= in.cur) goto yyeof2; goto yyFillLabel2;
case 3: if (in.lim <= in.cur) goto yyeof3; goto yyFillLabel3;
case 4: if (in.lim <= in.cur) goto yyeof4; goto yyFillLabel4;
case 5: if (in.lim <= in.cur) goto yyeof5; goto yyFillLabel5;
case 6: if (in.lim <= in.cur) goto yyeof6; goto yyFillLabel6;
case 7: if (in.lim <= in.cur) goto yyeof7; goto yyFillLabel7;
case 8: if (in.lim <= in.cur) goto yyeof8; goto yyFillLabel8;
case 9: if (in.lim <= in.cur) goto yyeof9; goto yyFillLabel9;
case 10: if (in.lim <= in.cur) goto yyeof10; goto yyFillLabel10;
case 11: if (in.lim <= in.cur) goto yyeof11; goto yyFillLabel11;
case 12: if (in.lim <= in.cur) goto yyeof12; goto yyFillLabel12;
case 13: if (in.lim <= in.cur) goto yyeof13; goto yyFillLabel13;
case 14: if (in.lim <= in.cur) goto yyeof14; goto yyFillLabel14;
case 15: if (in.lim <= in.cur) goto yyeof15; goto yyFillLabel15;
case 16: if (in.lim <= in.cur) goto yyeof16; goto yyFillLabel16;
case 17: if (in.lim <= in.cur) goto yyeof17; goto yyFillLabel17;
case 18: if (in.lim <= in.cur) goto yyeof18; goto yyFillLabel18;
case 19: if (in.lim <= in.cur) goto yyeof19; goto yyFillLabel19;
case 20: if (in.lim <= in.cur) goto yyeof20; goto yyFillLabel20;
}



yy0:
yyFillLabel0:
	in.yych = *in.cur;
	switch (in.yych) {
	case '\n':
	case ' ':	goto yy4;
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy7;
	case 'T':	goto yy10;
	default:
		if (in.lim <= in.cur) {
			YYSETSTATE(0);
			YYFILL();
yyeof0:
			goto yyeofrule1;
		}
		goto yy2;
	}
yy2:
	++in.cur;
	{ printf("< Unexpected character >%c<\n", in.yych); return FAIL; }
yy4:
	++in.cur;
yyFillLabel1:
	in.yych = *in.cur;
	switch (in.yych) {
	case '\n':
	case ' ':	goto yy4;
	default:
		if (in.lim <= in.cur) {
			YYSETSTATE(1);
			YYFILL();
yyeof1:
			;
		}
		goto yy6;
	}
yy6:
	{ printf("< whitespace\n");                         return WHITESPACE; }
yy7:
	++in.cur;
yyFillLabel2:
	in.yych = *in.cur;
yy8:
	switch (in.yych) {
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F':
	case 'G':
	case 'H':
	case 'I':
	case 'J':
	case 'K':
	case 'L':
	case 'M':
	case 'N':
	case 'O':
	case 'P':
	case 'Q':
	case 'R':
	case 'S':
	case 'T':
	case 'U':
	case 'V':
	case 'W':
	case 'X':
	case 'Y':
	case 'Z':
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
	case 'g':
	case 'h':
	case 'i':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'o':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'u':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':	goto yy7;
	default:
		if (in.lim <= in.cur) {
			YYSETSTATE(2);
			YYFILL();
yyeof2:
			;
		}
		goto yy9;
	}
yy9:
	{ printf("< word\n");                               return WORD; }
yy10:
	++in.cur;
yyFillLabel3:
	in.yych = *in.cur;
	switch (in.yych) {
	case 0x00:
		if (in.lim <= in.cur) {
			YYSETSTATE(3);
			YYFILL();
yyeof3:
			;
		}
		goto yy9;
	case 'H':	goto yy11;
	default:	goto yy8;
	}
yy11:
	++in.cur;
yyFillLabel4:
	in.yych = *in.cur;
	switch (in.yych) {
	case 0x00:
		if (in.lim <= in.cur) {
			YYSETSTATE(4);
			YYFILL();
yyeof4:
			;
		}
		goto yy9;
	case 'I':	goto yy12;
	default:	goto yy8;
	}
yy12:
	++in.cur;
yyFillLabel5:
	in.yych = *in.cur;
	switch (in.yych) {
	case 0x00:
		if (in.lim <= in.cur) {
			YYSETSTATE(5);
			YYFILL();
yyeof5:
			;
		}
		goto yy9;
	case 'N':	goto yy13;
	default:	goto yy8;
	}
yy13:
	++in.cur;
yyFillLabel6:
	in.yych = *in.cur;
	switch (in.yych) {
	case 0x00:
		if (in.lim <= in.cur) {
			YYSETSTATE(6);
			YYFILL();
yyeof6:
			;
		}
		goto yy9;
	case 'G':	goto yy14;
	default:	goto yy8;
	}
yy14:
	in.mark = ++in.cur;
yyFillLabel7:
	in.yych = *in.cur;
	switch (in.yych) {
	case 0x00:
		if (in.lim <= in.cur) {
			YYSETSTATE(7);
			YYFILL();
yyeof7:
			;
		}
		goto yy9;
	case '\n':	goto yy15;
	default:	goto yy8;
	}
yy15:
	++in.cur;
yyFillLabel8:
	in.yych = *in.cur;
	switch (in.yych) {
	case 'W':	goto yy17;
	default:
		if (in.lim <= in.cur) {
			YYSETSTATE(8);
			YYFILL();
yyeof8:
			;
		}
		goto yy16;
	}
yy16:
	in.cur = in.mark;
	goto yy9;
yy17:
	++in.cur;
yyFillLabel9:
	in.yych = *in.cur;
	switch (in.yych) {
	case 'I':	goto yy18;
	default:
		if (in.lim <= in.cur) {
			YYSETSTATE(9);
			YYFILL();
yyeof9:
			;
		}
		goto yy16;
	}
yy18:
	++in.cur;
yyFillLabel10:
	in.yych = *in.cur;
	switch (in.yych) {
	case 'T':	goto yy19;
	default:
		if (in.lim <= in.cur) {
			YYSETSTATE(10);
			YYFILL();
yyeof10:
			;
		}
		goto yy16;
	}
yy19:
	++in.cur;
yyFillLabel11:
	in.yych = *in.cur;
	switch (in.yych) {
	case 'H':	goto yy20;
	default:
		if (in.lim <= in.cur) {
			YYSETSTATE(11);
			YYFILL();
yyeof11:
			;
		}
		goto yy16;
	}
yy20:
	++in.cur;
yyFillLabel12:
	in.yych = *in.cur;
	switch (in.yych) {
	case '\n':	goto yy21;
	default:
		if (in.lim <= in.cur) {
			YYSETSTATE(12);
			YYFILL();
yyeof12:
			;
		}
		goto yy16;
	}
yy21:
	++in.cur;
yyFillLabel13:
	in.yych = *in.cur;
	switch (in.yych) {
	case 'N':	goto yy22;
	default:
		if (in.lim <= in.cur) {
			YYSETSTATE(13);
			YYFILL();
yyeof13:
			;
		}
		goto yy16;
	}
yy22:
	++in.cur;
yyFillLabel14:
	in.yych = *in.cur;
	switch (in.yych) {
	case 'E':	goto yy23;
	default:
		if (in.lim <= in.cur) {
			YYSETSTATE(14);
			YYFILL();
yyeof14:
			;
		}
		goto yy16;
	}
yy23:
	++in.cur;
yyFillLabel15:
	in.yych = *in.cur;
	switch (in.yych) {
	case 'W':	goto yy24;
	default:
		if (in.lim <= in.cur) {
			YYSETSTATE(15);
			YYFILL();
yyeof15:
			;
		}
		goto yy16;
	}
yy24:
	++in.cur;
yyFillLabel16:
	in.yych = *in.cur;
	switch (in.yych) {
	case 'L':	goto yy25;
	default:
		if (in.lim <= in.cur) {
			YYSETSTATE(16);
			YYFILL();
yyeof16:
			;
		}
		goto yy16;
	}
yy25:
	++in.cur;
yyFillLabel17:
	in.yych = *in.cur;
	switch (in.yych) {
	case 'I':	goto yy26;
	default:
		if (in.lim <= in.cur) {
			YYSETSTATE(17);
			YYFILL();
yyeof17:
			;
		}
		goto yy16;
	}
yy26:
	++in.cur;
yyFillLabel18:
	in.yych = *in.cur;
	switch (in.yych) {
	case 'N':	goto yy27;
	default:
		if (in.lim <= in.cur) {
			YYSETSTATE(18);
			YYFILL();
yyeof18:
			;
		}
		goto yy16;
	}
yy27:
	++in.cur;
yyFillLabel19:
	in.yych = *in.cur;
	switch (in.yych) {
	case 'E':	goto yy28;
	default:
		if (in.lim <= in.cur) {
			YYSETSTATE(19);
			YYFILL();
yyeof19:
			;
		}
		goto yy16;
	}
yy28:
	++in.cur;
yyFillLabel20:
	in.yych = *in.cur;
	switch (in.yych) {
	case 'S':	goto yy29;
	default:
		if (in.lim <= in.cur) {
			YYSETSTATE(20);
			YYFILL();
yyeof20:
			;
		}
		goto yy16;
	}
yy29:
	++in.cur;
	{ printf("< Thing w/ newlines\n");                  return THING; }
yyeofrule1:
	{ printf("< EOF\n");                                return OK; }

}

int main()
{
  int fds[2];
  pipe(fds);
  fcntl(fds[0], F_SETFL, fcntl(fds[0], F_GETFL) | O_NONBLOCK);
  FILE * write = fdopen(fds[1], "w");
  FILE * read = fdopen(fds[0], "r");
  input_t in(read);

  const char * packets[] = {
    "THING\n",
    "WITH\n",
    "NEWLINES\n",
    "H", "E", "L", "O", "\n",
    "HELO\n",
    "THING\nWITH\n",
    "NEWLINES"
  };
  size_t num_packets = sizeof(packets) / sizeof(char *);
  size_t current_packet = 0;

  enum status_t result = NEED_MORE_INPUT;

  while (OK != result) {
    switch (result) {
      case NEED_MORE_INPUT:
        if (current_packet == num_packets) {
          printf("Not enough input\n");
          goto end;
        }

        fwrite(packets[current_packet], strlen(packets[current_packet]), 1, write);
        fflush(write);
        current_packet++;
        printf("Packet %lu / %lu written\n", current_packet, num_packets);

        if (current_packet == num_packets) {
          printf("%lu / %lu packets sent, Closing down communication channel\n",
            current_packet, num_packets);
          fclose(write);
          write = NULL;
        }

        in.fill();
        break;

      case FAIL:
        goto end;

      default:
        // careful, need to reset state (re2c forgets to do it)
        YYSETSTATE(0);
        break;
    }

    result = lex(in);
    printf("Received response from lexer: %s\n", STATUSES[result]);
  }

end:

  // cleanup
  fclose(read);
  if (write) {
    fclose(write);
  }

  return result == OK ? 0 : 1;
}

#undef YYGETSTATE
#undef YYSETSTATE
#undef YYFILL
