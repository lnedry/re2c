// Code generated by re2c, DO NOT EDIT.
//line "go/state/push.f--lang(go).re":1
//go:generate re2go -f $INPUT -o $OUTPUT
package main

import (
	"fmt"
	"os"
	"testing"
)

// Intentionally small to trigger buffer refill.
const SIZE int = 16

type Input struct {
	file     *os.File
	data     []byte
	cursor   int
	marker   int
	token    int
	limit    int
	state    int
	yyaccept int
}

const (
	lexEnd = iota
	lexReady
	lexWaitingForInput
	lexPacketBroken
	lexPacketTooBig
	lexCountMismatch
)

func fill(in *Input) int {
	if in.token == 0 {
		// Error: no space can be freed.
		// In real life can reallocate a larger buffer.
		return lexPacketTooBig
	}

	// Discard everything up to the start of the current lexeme,
	// shift buffer contents and adjust offsets.
	copy(in.data[0:], in.data[in.token:in.limit])
	in.cursor -= in.token
	in.marker -= in.token
	in.limit -= in.token
	in.token = 0

	// Read new data (as much as possible to fill the buffer).
	n, _ := in.file.Read(in.data[in.limit:SIZE])
	in.limit += n
	in.data[in.limit] = 0 // append sentinel symbol

	return lexReady
}

func lex(in *Input, recv *int) int {
	var yych byte
	switch (in.state) {
default:
	goto yy0
case 0:
	if (in.limit <= in.cursor) {
		goto yyeof1
	}
	goto yyFillLabel0
case 1:
	if (in.limit <= in.cursor) {
		goto yy4
	}
	goto yyFillLabel1
case 2:
	if (in.limit <= in.cursor) {
		goto yy10
	}
	goto yyFillLabel2
}

loop:
	in.token = in.cursor
	
//line "go/state/push.f--lang(go).go":84

yy0:
yyFillLabel0:
	yych = in.data[in.cursor]
	switch (yych) {
	case 'a':
		fallthrough
	case 'b':
		fallthrough
	case 'c':
		fallthrough
	case 'd':
		fallthrough
	case 'e':
		fallthrough
	case 'f':
		fallthrough
	case 'g':
		fallthrough
	case 'h':
		fallthrough
	case 'i':
		fallthrough
	case 'j':
		fallthrough
	case 'k':
		fallthrough
	case 'l':
		fallthrough
	case 'm':
		fallthrough
	case 'n':
		fallthrough
	case 'o':
		fallthrough
	case 'p':
		fallthrough
	case 'q':
		fallthrough
	case 'r':
		fallthrough
	case 's':
		fallthrough
	case 't':
		fallthrough
	case 'u':
		fallthrough
	case 'v':
		fallthrough
	case 'w':
		fallthrough
	case 'x':
		fallthrough
	case 'y':
		fallthrough
	case 'z':
		goto yy5
	default:
		if (in.limit <= in.cursor) {
			in.state = 0
			return lexWaitingForInput
		}
		goto yy3
	}
yy3:
	in.cursor += 1
yy4:
//line "go/state/push.f--lang(go).re":74
	{ return lexPacketBroken }
//line "go/state/push.f--lang(go).go":154
yy5:
	in.cursor += 1
	in.marker = in.cursor
yyFillLabel1:
	yych = in.data[in.cursor]
	switch (yych) {
	case ';':
		goto yy6
	case 'a':
		fallthrough
	case 'b':
		fallthrough
	case 'c':
		fallthrough
	case 'd':
		fallthrough
	case 'e':
		fallthrough
	case 'f':
		fallthrough
	case 'g':
		fallthrough
	case 'h':
		fallthrough
	case 'i':
		fallthrough
	case 'j':
		fallthrough
	case 'k':
		fallthrough
	case 'l':
		fallthrough
	case 'm':
		fallthrough
	case 'n':
		fallthrough
	case 'o':
		fallthrough
	case 'p':
		fallthrough
	case 'q':
		fallthrough
	case 'r':
		fallthrough
	case 's':
		fallthrough
	case 't':
		fallthrough
	case 'u':
		fallthrough
	case 'v':
		fallthrough
	case 'w':
		fallthrough
	case 'x':
		fallthrough
	case 'y':
		fallthrough
	case 'z':
		goto yy8
	default:
		if (in.limit <= in.cursor) {
			in.state = 1
			return lexWaitingForInput
		}
		goto yy4
	}
yy6:
	in.cursor += 1
//line "go/state/push.f--lang(go).re":76
	{ *recv = *recv + 1; goto loop }
//line "go/state/push.f--lang(go).go":226
yy8:
	in.cursor += 1
yyFillLabel2:
	yych = in.data[in.cursor]
	switch (yych) {
	case ';':
		goto yy6
	case 'a':
		fallthrough
	case 'b':
		fallthrough
	case 'c':
		fallthrough
	case 'd':
		fallthrough
	case 'e':
		fallthrough
	case 'f':
		fallthrough
	case 'g':
		fallthrough
	case 'h':
		fallthrough
	case 'i':
		fallthrough
	case 'j':
		fallthrough
	case 'k':
		fallthrough
	case 'l':
		fallthrough
	case 'm':
		fallthrough
	case 'n':
		fallthrough
	case 'o':
		fallthrough
	case 'p':
		fallthrough
	case 'q':
		fallthrough
	case 'r':
		fallthrough
	case 's':
		fallthrough
	case 't':
		fallthrough
	case 'u':
		fallthrough
	case 'v':
		fallthrough
	case 'w':
		fallthrough
	case 'x':
		fallthrough
	case 'y':
		fallthrough
	case 'z':
		goto yy8
	default:
		if (in.limit <= in.cursor) {
			in.state = 2
			return lexWaitingForInput
		}
		goto yy10
	}
yy10:
	in.cursor = in.marker
	goto yy4
yyeof1:
//line "go/state/push.f--lang(go).re":75
	{ return lexEnd }
//line "go/state/push.f--lang(go).go":299
//line "go/state/push.f--lang(go).re":77

}

func test(packets []string) int {
	fname := "pipe"
	fw, _ := os.Create(fname);
	fr, _ := os.Open(fname);

	in := &Input{
		file:   fr,
		data:   make([]byte, SIZE+1),
		cursor: SIZE,
		marker: SIZE,
		token:  SIZE,
		limit:  SIZE,
		state:  -1,
	}
	// data is zero-initialized, no need to write sentinel

	var status int
	send := 0
	recv := 0
loop:
	for {
		status = lex(in, &recv)
		if status == lexEnd {
			if send != recv {
				status = lexCountMismatch
			}
			break loop
		} else if status == lexWaitingForInput {
			if send < len(packets) {
				fw.WriteString(packets[send])
				send += 1
			}
			status = fill(in)
			if status != lexReady {
				break loop
			}
		} else if status == lexPacketBroken {
			break loop
		} else {
			panic("unexpected status")
		}
	}

	fr.Close()
	fw.Close()
	os.Remove(fname)

	return status
}

func TestLex(t *testing.T) {
	var tests = []struct {
		status  int
		packets []string
	}{
		{lexEnd, []string{}},
		{lexEnd, []string{"zero;", "one;", "two;", "three;", "four;"}},
		{lexPacketBroken, []string{"??;"}},
		{lexPacketTooBig, []string{"looooooooooooong;"}},
	}

	for i, x := range tests {
		t.Run(fmt.Sprintf("%d", i), func(t *testing.T) {
			status := test(x.packets)
			if status != x.status {
				t.Errorf("got %d, want %d", status, x.status)
			}
		})
	}
}