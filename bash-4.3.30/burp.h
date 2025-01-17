#ifndef __BURP_H__
#define __BURP_H__

#include "fix_string.h"

#ifndef TRUE
#  define TRUE 1
#  define FALSE 0
#endif

#define BASH2PY_STDIN 0
#define BASH2PY_STDOUT 1
#define BASH2PY_STDERR 2

typedef struct {
	char	*m_P;
	int 	m_lth;
	int		m_max;
	int		m_indent;
	_BOOL	m_disable_indent;
	int		m_ungetc;
} burpT;

void burp_reset(burpT *burpP);
char *burp_extend(burpT *burpP, int offset, int need);
void burp(burpT *burpP, const char *fmtP, ...);
void burpc(burpT *burpP, const char c);
void burp_ungetc(burpT *burpP);
void burpn(burpT *burpP, const char *stringP, int lth);
void burps(burpT *burpP, const char *stringP);
void burps_html(burpT *burpP, const char *stringP);
void burp_esc_quote(burpT *burpP, int offset, int quote);
void burp_rtrim(burpT *burpP);

#define INDENT(X) X.m_indent++
#define OUTDENT(X) { assert(0 < X.m_indent); X.m_indent--; }

void log_init();
void log_close();
void log_activate();
void log_deactivate();
void log_enter(char *format, ...);
void log_info(char *format, ...);
void log_return();
void log_return_msg(char *msg_template, ...);

char *bool_to_text(_BOOL value);
char *type_to_text(fix_typeE value);

#endif // __BURP_H__
