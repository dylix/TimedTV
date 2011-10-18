/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Library General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor Boston, MA 02110-1301,  USA
 */
 
#include <gtk/gtk.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <gdk/gdkkeysyms.h>
#include <pthread.h>
#include <time.h>

/*#include <cairo.h>*/
/*#include <stdio.h>*/

#include "version.h"

static GtkWidget *entMin;
static GtkWidget *chkMon;
static int timerEnabled;
static long currentTime, endTime;
static pid_t pid;

#ifdef __SUNPRO_C
#pragma align 4 (my_pixbuf)
#endif
#ifdef __GNUC__
static const guint8 my_pixbuf[] __attribute__ ((__aligned__ (4))) = 
#else
static const guint8 my_pixbuf[] = 
#endif
{ ""
  /* Pixbuf magic (0x47646b50) */
  "GdkP"
  /* length: header (24) + pixel_data (3434) */
  "\0\0\15\202"
  /* pixdata_type (0x2010002) */
  "\2\1\0\2"
  /* rowstride (192) */
  "\0\0\0\300"
  /* width (48) */
  "\0\0\0""0"
  /* height (48) */
  "\0\0\0""0"
  /* pixel_data: */
  "\340\377\377\377\0\4\200\200\200\6{{{:sss>qqqD\206jjjH\206lllG\2mmmF"
  "lllG\210mmmF\202oooE\203kkkE\215mmmD\16rrrCppp@{{{:\200\200\200\6\213"
  "\213\212\275\270\270\265\371\263\263\260\372\245\245\244\373\242\242"
  "\240\373\236\236\234\374\242\242\240\373\244\244\242\373\241\241\240"
  "\373\245\245\243\373\202\253\253\252\373\202\254\254\252\373\202\255"
  "\255\254\373\202\256\256\255\373\202\257\257\256\373\4\256\256\256\373"
  "\256\256\255\373\257\257\256\373\260\260\260\373\202\260\260\257\373"
  "\202\257\257\257\373\202\257\257\256\373\2\256\256\256\373\256\256\255"
  "\373\202\256\256\254\373\1\255\255\254\373\203\254\254\252\373\2\253"
  "\253\252\373\253\253\251\373\202\253\253\250\373\16\253\253\251\373\252"
  "\252\250\373\253\253\250\373\255\255\253\372\263\263\257\371\212\212"
  "\210\275\201\201~\346\323\323\317\377\312\312\307\377\262\262\257\377"
  "\253\254\250\377\257\257\254\377\236\237\233\377\246\246\243\377\202"
  "\253\254\250\377\1\311\311\306\377\202\311\311\307\377\1\311\311\310"
  "\377\202\313\313\311\377\7\314\314\312\377\314\314\313\377\316\316\314"
  "\377\317\317\315\377\317\317\316\377\317\317\315\377\317\317\317\377"
  "\202\320\320\317\377\202\317\317\317\377\2\317\317\316\377\317\317\315"
  "\377\202\316\316\314\377\2\315\315\313\377\315\315\312\377\202\314\314"
  "\311\377\2\312\312\307\377\312\312\306\377\202\311\311\306\377\15\310"
  "\310\305\377\310\310\304\377\307\307\304\377\307\307\303\377\306\306"
  "\303\377\307\307\302\377\311\311\304\377\316\316\311\377~~|\346vvs\350"
  "\323\323\320\377\317\316\314\377mdZ\377\210\201kX\377\204\202lX\377\216"
  "\202lY\377\203\202lX\377\210\201kX\377\203\201kW\377\10og]\377\322\322"
  "\315\377\317\317\312\377ssr\350uus\350\323\323\320\377\317\317\313\377"
  "\212mT\377\205\365z\30\377\205\365y\30\377\203\365y\27\377\207\365x\27"
  "\377\202\365x\26\377\210\365w\26\377\1\365w\25\377\211\365v\25\377\10"
  "}jZ\377\322\322\315\377\317\317\312\377ssq\350uur\350\323\323\320\377"
  "\317\317\313\377\212nU\377\211\365}\33\377\211\365|\32\377\202\365{\32"
  "\377\206\365{\31\377\204\365z\31\377\205\365z\30\377\205\365y\30\377"
  "\10}k[\377\322\322\315\377\317\317\312\377rrq\350uur\350\323\323\320"
  "\377\317\317\313\377\212oV\377\204\365\201\36\377\205\365\200\36\377"
  "\204\365\200\35\377\207\365\177\35\377\202\365\177\34\377\210\365~\34"
  "\377\1\365~\33\377\211\365}\33\377\10}k[\377\322\322\315\377\317\317"
  "\312\377rrq\350ssr\350\323\323\320\377\317\317\313\377\213pV\377\211"
  "\366\204!\377\210\366\203\40\377\203\366\202\40\377\206\366\202\37\377"
  "\202\366\201\37\377\202\365\201\37\377\205\365\201\36\377\205\365\200"
  "\36\377\10}l[\377\322\322\315\377\317\317\312\377rrp\350ssq\350\323\323"
  "\320\377\317\317\313\377\213pW\377\204\366\210$\377\205\366\207$\377"
  "\204\366\207#\377\207\366\206#\377\202\366\206\"\377\210\366\205\"\377"
  "\1\366\205!\377\211\366\204!\377\10}l\\\377\322\322\315\377\317\317\312"
  "\377qqp\350rrp\350\323\323\320\377\317\317\313\377\213qW\377\210\366"
  "\213'\377\1\366\212'\377\210\366\212&\377\202\366\211&\377\207\366\211"
  "%\377\204\366\210%\377\205\366\210$\377\205\366\207$\377\10}m\\\377\322"
  "\322\315\377\317\317\312\377ppo\350qqp\350\323\323\320\377\317\317\313"
  "\377\213rX\377\204\367\217*\377\205\367\216*\377\203\367\216)\377\1\366"
  "\216)\377\206\366\215)\377\203\366\215(\377\210\366\214(\377\211\366"
  "\213'\377\11\366\212'\377}m\\\377\322\322\315\377\317\317\312\377ppn"
  "\350qqo\350\323\323\320\377\317\317\313\377\213rY\377\210\367\222-\377"
  "\1\367\221-\377\210\367\221,\377\202\367\220,\377\207\367\220+\377\204"
  "\367\217+\377\205\367\217*\377\205\367\216*\377\10}m]\377\322\322\315"
  "\377\317\317\312\377oon\350ppo\351\323\323\320\377\317\317\313\377\213"
  "sY\377\204\367\2260\377\205\367\2250\377\204\367\225/\377\206\367\224"
  "/\377\202\367\224.\377\210\367\223.\377\1\367\223-\377\211\367\222-\377"
  "\11\367\221-\377}n]\377\322\322\315\377\317\317\312\377ool\351ppo\351"
  "\323\323\320\377\317\317\313\377\213tZ\377\210\367\2313\377\1\367\230"
  "3\377\210\367\2302\377\202\367\2272\377\207\367\2271\377\204\367\226"
  "1\377\205\367\2260\377\205\367\2250\377\10}n]\377\322\322\315\377\317"
  "\317\312\377ool\351ppm\351\323\323\320\377\317\317\313\377\213tZ\377"
  "\204\370\2356\377\205\370\2346\377\203\370\2345\377\207\370\2335\377"
  "\202\370\2334\377\206\370\2324\377\202\367\2324\377\1\367\2323\377\211"
  "\367\2313\377\11\367\2302\377}n^\377\322\322\315\377\317\317\312\377"
  "mml\351oom\351\323\323\320\377\317\317\313\377\213u[\377\210\370\240"
  "9\377\1\370\2379\377\210\370\2378\377\202\370\2368\377\206\370\2367\377"
  "\204\370\2357\377\206\370\2356\377\205\370\2346\377\10}o^\377\322\322"
  "\315\377\317\317\312\377mmk\351ool\351\323\323\320\377\317\317\313\377"
  "\213u\\\377\216\370\241;\377\206\370\241:\377\207\370\240:\377\213\370"
  "\2409\377\12\370\2379\377\370\2378\377}o^\377\322\322\315\377\317\317"
  "\312\377llk\351mml\351\323\323\320\377\317\317\313\377\213v\\\377\204"
  "\370\242>\377\216\370\242=\377\204\370\242<\377\211\370\241<\377\211"
  "\370\241;\377\10}p_\377\322\322\315\377\317\317\312\377llj\351mml\351"
  "\323\323\320\377\317\317\313\377\213v]\377\210\370\243@\377\215\370\243"
  "\77\377\203\370\243>\377\213\370\242>\377\205\370\242=\377\10}p_\377"
  "\322\322\315\377\317\317\312\377llj\351mmk\351\323\323\320\377\317\317"
  "\313\377\213v]\377\214\370\244B\377\215\370\244A\377\1\370\244@\377\215"
  "\370\243@\377\11\370\243\77\377}p_\377\322\322\315\377\317\317\312\377"
  "kkj\351llk\351\323\323\320\377\317\317\313\377\213v^\377\202\370\245"
  "E\377\215\370\245D\377\215\370\245C\377\1\370\244C\377\213\370\244B\377"
  "\11}p`\377\322\322\315\377\316\316\311\377kki\351kkj\351\323\323\320"
  "\377\317\317\313\377\213w^\377\370\247G\377\205\370\246G\377\215\370"
  "\246F\377\212\370\246E\377\204\370\245E\377\207\370\245D\377\10}p`\377"
  "\322\322\315\377\316\316\311\377jji\351kki\351\323\323\320\377\317\317"
  "\313\377\213w^\377\203\371\250I\377\206\370\247I\377\216\370\247H\377"
  "\210\370\247G\377\205\370\246G\377\204\370\246F\377\10}p`\377\322\322"
  "\315\377\316\316\311\377iih\351jji\352\323\323\320\377\317\317\313\377"
  "\213w_\377\205\371\251K\377\210\371\250K\377\216\371\250J\377\206\371"
  "\250I\377\207\370\247I\377\10}p`\377\322\322\315\377\316\316\311\377"
  "iih\352jjh\352\323\323\320\377\317\317\313\377\213w`\377\203\371\252"
  "N\377\204\371\252M\377\212\371\251M\377\215\371\251L\377\205\371\251"
  "K\377\205\371\250K\377\10~pa\377\322\322\315\377\316\316\311\377hhf\352"
  "jjh\352\323\323\320\377\317\317\313\377\213x`\377\207\371\253P\377\202"
  "\371\253O\377\214\371\252O\377\215\371\252N\377\204\371\252M\377\202"
  "\371\251M\377\10~pa\377\322\322\315\377\316\316\311\377hhf\352iih\352"
  "\323\323\320\377\317\317\313\377\213xa\377\213\371\254R\377\215\371\253"
  "Q\377\216\371\253P\377\202\371\253O\377\11~qa\377\322\322\315\377\316"
  "\316\311\377hhe\352iif\352\323\323\320\377\317\317\313\377\213xa\377"
  "\371\255U\377\214\371\255T\377\202\371\254T\377\215\371\254S\377\214"
  "\371\254R\377\10~qa\377\322\322\315\377\316\316\311\377ffe\352hhf\352"
  "\323\323\320\377\317\317\313\377\213xb\377\205\371\256W\377\212\371\256"
  "V\377\203\371\255V\377\216\371\255U\377\210\371\255T\377\10~qb\377\322"
  "\322\315\377\316\316\311\377ffd\352hhe\352\323\323\320\377\317\317\313"
  "\377\210wa\377\211\357\252X\377\210\357\252W\377\223\357\251W\377\204"
  "\357\251V\377\10|pa\377\322\322\315\377\316\316\311\377eed\352hhf\352"
  "\323\323\320\377\321\321\316\377\207\177t\377\204\210~q\377\204\210~"
  "r\377\204\211\177r\377\205\211\177s\377\202\212\200s\377\3\212\200t\377"
  "\211\177s\377\212\200s\377\204\211\177s\377\203\211\177r\377\202\210"
  "~r\377\204\210~q\377\1\207}q\377\204\207}p\377\11\211\203y\377\322\322"
  "\315\377\316\316\311\377ffd\352{{x\347\325\325\321\377\325\325\322\377"
  "\326\326\322\377\326\326\323\377\202\327\327\324\377\1\330\330\325\377"
  "\202\331\331\326\377\4\332\332\327\377\332\332\330\377\333\333\330\377"
  "\333\333\331\377\202\334\334\332\377%\335\335\333\377\335\335\334\377"
  "\336\336\334\377\337\337\335\377\340\340\337\377\341\341\337\377\340"
  "\340\337\377\266\266\264\377\224\225\222\377\333\333\332\377\340\340"
  "\336\377\337\337\335\377\337\337\334\377\336\336\333\377\335\334\332"
  "\377\324\323\321\377\267\267\265\377\332\332\327\377\315\315\313\377"
  "\271\271\267\377\330\330\324\377\307\307\305\377\272\272\270\377\325"
  "\325\322\377\303\303\300\377\274\274\271\377\323\323\317\377\300\300"
  "\275\377\276\276\273\377\321\321\314\377\320\320\313\377xxv\347\231\230"
  "\226\341\307\306\303\377\300\300\275\377\301\301\275\377\301\301\276"
  "\377\202\302\302\277\377,\304\304\300\377\305\305\301\377\305\304\302"
  "\377\306\305\303\377\306\306\303\377\307\307\303\377\307\307\304\377"
  "\310\310\305\377\311\310\306\377\311\310\307\377\311\311\310\377\311"
  "\311\307\377\312\312\307\377\313\313\311\377\314\314\311\377\310\307"
  "\306\377\240\240\234\377\225\226\222\377\305\306\304\377\314\314\312"
  "\377\313\313\311\377\314\314\311\377\313\313\310\377\312\312\307\377"
  "\273\273\271\377\313\313\312\377\310\310\305\377\274\274\272\377\315"
  "\315\313\377\311\311\305\377\272\271\270\377\313\313\312\377\306\306"
  "\304\377\271\271\270\377\313\313\311\377\305\305\300\377\273\273\271"
  "\377\312\312\310\377\304\303\276\377\307\307\301\377\226\226\223\341"
  "\204\203\202\277\206\205\202\367\203\202~\371\202\203\202\177\371\202"
  "\202\201\177\371\1\203\202\177\371\202\203\202~\371\202\202\201\177\371"
  "\2\202\202~\371\202\202\177\371\203\204\203\177\371\5\204\203\200\371"
  "\203\202\200\371\204\203\200\371\203\203\177\373\202\202\177\373\202"
  "\203\202\177\373\11|{x\374\202\201~\373\202\201\177\373\202\202~\372"
  "\202\202\177\371\201\201~\371\201\200}\371\200\177}\371\200\177|\371"
  "\202\200\177}\371\203\200\177|\371\202\177~|\371\1\177~{\371\202~}z\371"
  "\202~}y\371\4\177~y\371\204\204\200\370\203\203\202\275\200\200\200\6"
  "\213www-\210ooo.\10\27\27\27\342\30\30\30\377:99\377\\[[\377HGG\377\33"
  "\32\32\377\25\24\24\377!!\37\244\222tto.\2www-fff\5\224\377\377\377\0"
  "\10\0\0\0\353\7\7\7\377777\377]]]\377HHH\377\11\11\11\377\0\0\0\377\0"
  "\0\0\227\250\377\377\377\0\10\0\0\0\372\10\10\10\377===\377```\377NN"
  "N\377\12\12\12\377\0\0\0\377\0\0\0\240\247\377\377\377\0\11\0\0\0\11"
  "\0\0\0\377\11\11\11\377CCC\377bbb\377UUU\377\13\13\13\377\0\0\0\377\0"
  "\0\0\251\247\377\377\377\0\11\0\0\0\30\0\0\0\377\7\7\7\377+++\377>>>"
  "\377666\377\7\7\7\377\0\0\0\377\0\0\0\261\245\377\377\377\0\16\0\0\0"
  "\12\10\10\10B\2\2\2\177\2\2\2\377\3\3\3\377\10\10\10\377\20\20\20\377"
  "\14\14\14\377\2\2\2\377\1\1\1\377\0\0\0\334\10\10\10`\5\5\5""1\0\0\0"
  "\1\236\377\377\377\0\6\0\0\0\10\32\32\32M,,,\230///\276+++\342!!!\376"
  "\202\21\21\21\377\15\16\16\16\377\14\14\14\377\11\11\11\377\7\7\7\377"
  "\5\5\5\377\2\2\2\377\0\0\0\377###\377<;;\366;;;\324<<<\256///\201\14"
  "\14\14)\232\377\377\377\0\27\20\20\20O\26\26\26\370...\375333\376777"
  "\377998\377444\377666\377;;;\377@@@\377CCC\377FFF\377PPP\377OOO\377L"
  "LL\377III\377YYY\377ddd\377hgg\377ggg\377aaa\376BBB\372\40\40\40\340"
  "\231\377\377\377\0\27\0\0\0\17\0\0\0\210\0\0\0\226\0\0\0\242\3\3\3\256"
  "\5\5\5\274\11\11\11\310\14\14\14\322\22\22\22\324\32\32\32\330$$$\327"
  ",,,\326---\323$$$\320\32\32\32\314\24\24\24\310\21\21\21\302\14\14\14"
  "\273\7\7\7\263\0\0\0\245\0\0\0\233\0\0\0\220\0\0\0[\240\377\377\377\0"
  "\11\0\0\0\2\0\0\0\13\0\0\0\24\0\0\0\36\0\0\0$\0\0\0\35\0\0\0\24\0\0\0"
  "\12\0\0\0\2\364\377\377\377\0"};

void show_about(GtkWidget *widget, gpointer data)
{
	gchar *license = 
	"TimedTV is free software; you can redistribute it and/or modify\n"
	"it under the terms of the GNU General Public License as published by\n"
	"the Free Software Foundation; either version 2 of the License, or\n"
	"(at your option) any later version.\n"
	"\n"
	"TimedTV is distributed in the hope that it will be useful,\n"
	"but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
	"MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
	"GNU General Public License for more details.\n"
	"\n"
	"You should have received a copy of the GNU General Public License\n"
	"along with Alarm Clock; if not, write to the Free Software Foundation,\n"
	"Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA\n";

	//GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file("tv.png", NULL);

	GtkWidget *dialog = gtk_about_dialog_new();
	//gtk_window_set_position(GTK_ABOUT_DIALOG(dialog), GTK_WIN_POS_CENTER);
	gtk_about_dialog_set_program_name(GTK_ABOUT_DIALOG(dialog), "TimedTV");
	gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(dialog), TIMEDTV_VERSION); 
	gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(dialog),  "\xc2\xa9 2011 Chris Hall <dylix98@gmail.com>");
	gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(dialog), "TimedTV is a simple program for turning off TVTime & your monitors after a set amount of time.");
	gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(dialog), "http://plutonicx.dyndns.org/?page=misc");
	gtk_about_dialog_set_license(GTK_ABOUT_DIALOG(dialog), license);
	gtk_about_dialog_set_logo(GTK_ABOUT_DIALOG(dialog), gdk_pixbuf_new_from_inline(-1, my_pixbuf, FALSE, NULL));
	//g_object_unref(pixbuf), pixbuf = NULL;
	gtk_dialog_run(GTK_DIALOG (dialog));
	gtk_widget_destroy(dialog);

}

/*GdkPixbuf *create_pixbuf(const gchar * filename)
{
   GdkPixbuf *pixbuf;
   GError *error = NULL;
   pixbuf = gdk_pixbuf_new_from_file(filename, &error);
   if(!pixbuf) {
      fprintf(stderr, "%s\n", error->message);
      g_error_free(error);
   }
   return pixbuf;
}*/

//old code from possible displaying kill time
//static char buffer[256];

static gboolean time_handler(GtkWidget *widget)
{
	//if (widget->window == NULL) return FALSE;
	
	// Always keep currentTime current
	currentTime= time(NULL);
	
	// If launch button has been clicked
	if (timerEnabled==1)
	{
		if (currentTime > endTime)
		{
			/*	save for later. might make current/kill time visible on app
			
			time_t curtime;
			struct tm *loctime;
			curtime = time(NULL);
			loctime = localtime(&curtime);
			strftime(buffer, 256, "%T", loctime);
			gtk_widget_queue_draw(widget);
			*/

			/* TRY TO CHECK IF TVTIME WAS KILLED BY USER
			 
			if (getpid()<0)
			{
				gtk_main_quit;
			}
			*/
			
			// Get ready to kill shit
			kill(pid,SIGUSR1);
			if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(chkMon)))
			{
				system("xset dpms force off");
			}
			kill(getpid(),SIGUSR1);
			
		}
	}
	return TRUE;
}


 
void *myTimer(void *arg)
{
	// Launch button has been clicked
	timerEnabled=1;
	
	// Ugly stuff to get number from spin button
	GtkSpinButton *spin;
	spin = GTK_SPIN_BUTTON(entMin);
	int minutes = gtk_spin_button_get_value_as_int(spin);
	
	// Set endTime
	time_t result;
	result = time(NULL);
	endTime = result+(minutes*60);
}

static void exec_tvtime(GtkWidget *widget, gpointer data)
{      
	// Thread, not sure why
	pthread_t writer_id;
	pthread_create (&writer_id, NULL, myTimer, NULL);
	
	// Create the fork
	pid = fork();
	if (pid == 0)
	{
		// This is the child process.  Execute the shell command.
		execl("/usr/bin/tvtime","tvtime","-m", (char *)0);
	}
}

int main( int argc, char *argv[])
{

	GtkWidget *launch;
	GtkWidget *close;
	//GtkWidget *darea;
	GtkWidget *window;
	GtkWidget *vbox;
	GtkWidget *hbox;
	GtkWidget *mainbox;
	GtkWidget *halign;
	GtkWidget *valign;
	GtkWidget *separator;
	GtkWidget *table;
	GtkWidget *lblMin;
	GtkWidget *lblMon;
	GtkAdjustment *adj;
	GtkWidget *menubar;
	GtkWidget *filemenu;
	GtkWidget *file;
	GtkWidget *helpmenu;
	GtkWidget *help;
	GtkWidget *about;
	GtkWidget *quit;
	GtkAccelGroup *accel_group = NULL;


	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(window), 250, 150);
	gtk_window_set_title(GTK_WINDOW(window), "TimedTV");
	//gtk_window_set_icon(GTK_WINDOW(window), create_pixbuf("tv.png"));
	//new gtk stuff maybe
	gtk_window_set_icon(GTK_WINDOW(window), gdk_pixbuf_new_from_inline(-1, my_pixbuf, FALSE, NULL));
	gtk_window_set_resizable(GTK_WINDOW(window),FALSE);

	// Setup window layout
	vbox = gtk_vbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	// Add Top Menu To Window
	menubar = gtk_menu_bar_new();
	filemenu = gtk_menu_new();
	helpmenu = gtk_menu_new();
	accel_group = gtk_accel_group_new();
	gtk_window_add_accel_group(GTK_WINDOW(window), accel_group);
	file = gtk_menu_item_new_with_mnemonic("_File");
	quit = gtk_image_menu_item_new_from_stock(GTK_STOCK_QUIT, accel_group);
	help = gtk_menu_item_new_with_mnemonic("_Help");
	about = gtk_image_menu_item_new_from_stock(GTK_STOCK_ABOUT, NULL);
	// fucking gtk3 //gtk_widget_add_accelerator(quit, "activate", accel_group, GDK_q, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE); 
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(file), filemenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), quit);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), file);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), about);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 3);


	// Main VBOX
	mainbox = gtk_vbox_new(TRUE, 3);
	gtk_container_add(GTK_CONTAINER(vbox), mainbox);
	
	// Setup table
	table = gtk_table_new(3, 2, FALSE);
	gtk_container_add(GTK_CONTAINER(mainbox), table);
	
	// Labels
	lblMin = gtk_label_new("Minutes?");
	gtk_misc_set_alignment(GTK_MISC(lblMin),0,1);
	lblMon = gtk_label_new("Turn monitor off?");
	gtk_misc_set_alignment(GTK_MISC(lblMon),0,1);
	
	// Add labels to table
	gtk_table_attach(GTK_TABLE(table), lblMin, 0, 1, 0, 1, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
	gtk_table_attach(GTK_TABLE(table), lblMon, 0, 1, 1, 2, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
	
	// Spinner, checkbox
	adj = (GtkAdjustment *)gtk_adjustment_new(60.0, 0.0, 180.0, 5.0, 5.0, 0.0);
	entMin = gtk_spin_button_new (adj, 0, 0);
	gtk_spin_button_set_wrap(GTK_SPIN_BUTTON (entMin), TRUE);
	chkMon = gtk_check_button_new_with_label("Yes");
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(chkMon),TRUE);

	// Add spinner, checkbox to table...
	gtk_table_attach(GTK_TABLE(table), entMin, 1, 2, 0, 1, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);
	gtk_table_attach(GTK_TABLE(table), chkMon, 1, 2, 1, 2, GTK_FILL | GTK_SHRINK, GTK_FILL | GTK_SHRINK, 5, 5);

	
	// Area to display current/kill date
	//darea = gtk_drawing_area_new();
	//gtk_container_add(GTK_CONTAINER (mainbox), darea);
	
	
	//Add Horizontal Seperator
	separator = gtk_hseparator_new ();
	gtk_box_pack_start (GTK_BOX (vbox), separator, FALSE, TRUE, 5);


	// Add Two Buttons on Bottom
	hbox = gtk_hbox_new(TRUE, 3);
	launch = gtk_button_new_with_label("Launch TvTime");
	gtk_container_add(GTK_CONTAINER(hbox), launch);
	//gtk_window_set_default(window, launch);
	
	close = gtk_button_new_with_label("Exit");
	gtk_container_add(GTK_CONTAINER(hbox), close);
	halign = gtk_alignment_new(.5,0, 0, 0);
	gtk_container_add(GTK_CONTAINER(halign), hbox);
	gtk_box_pack_start(GTK_BOX(vbox), halign, FALSE, FALSE, 5);

	// TRY TO SET DEFAULTS
	gtk_widget_set_can_default(launch, TRUE);
	gtk_widget_grab_default(launch);
	
	// SIGNALS AND CALLBACKS
	g_signal_connect_swapped(G_OBJECT(window), "destroy",
	G_CALLBACK(gtk_main_quit), NULL);

	g_signal_connect(G_OBJECT(quit), "activate",
	G_CALLBACK(gtk_main_quit), NULL);
	
	g_signal_connect(G_OBJECT(about), "activate",
	G_CALLBACK(show_about), NULL);
	
	g_signal_connect(G_OBJECT(close), "clicked",
	G_CALLBACK(gtk_main_quit), NULL);
	
	g_signal_connect(G_OBJECT(launch), "clicked",
	G_CALLBACK(exec_tvtime), NULL);

    g_signal_connect (G_OBJECT (entMin), "activate",
    G_CALLBACK (exec_tvtime), NULL); 
                         
	//g_signal_connect(darea, "expose-event",
	//G_CALLBACK(on_expose_event), NULL);

	g_timeout_add(1000, (GSourceFunc) time_handler, (gpointer) window);
	gtk_widget_show_all(window);
	time_handler(window);

	gtk_main();

	return 0;
}
/* GdkPixbuf RGBA C-Source image dump 1-byte-run-length-encoded */
