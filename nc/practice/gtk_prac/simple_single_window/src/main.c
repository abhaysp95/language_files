// main file

#include <stdio.h>
#include <gtk/gtk.h>

// activate signal is connected to activate function
/* inside this function we want to create our gtk window */
static void activate(GtkApplication* app, gpointer user_data) {
	GtkWidget* window;
	// call to gtk_application_window_new() will create new GtkWindow and store to window pointer
	window = gtk_application_window_new(app);
	// the gtk_window_set_title() takes GtkWindow* and name as string
	/* as our window pointer is a GtkWidget pointer, we need to cast it to
	 * GtkWindow*. But instead of casting 'window' via 'GtkWindow*', 'window'
	 * can be cast using the macro 'GTK_WINDOW()'. GTK_WINDOW() will check if
	 * the pointer is an instance of the GtkWindow class, before casting, and
	 * emit a warning if the check fails. */
	gtk_window_set_title(GTK_WINDOW(window), "Window");
	gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);
	gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
	GtkApplication *app; // GtkApplication pointer
	int status;

	// initialization of GtkApplication pointer app
	/* pick an application identifier(name) for your application and input it
	 * as parameter for gtk_application_new, lastly gtk_application_new takes
	 * GApplicationFlag as input incase for special needs */
	app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
	// g_application_run sends activate signal,so activate() signal is sent and
	// we then proceed to activate() function
	/* when you exit the window by pressing 'X', g_application_run() returns
	 * with a number which is saved inside an integer named "status".
	 * Afterwards, the 'GtkApplication' object is freed from the memory with
	 * 'g_object_unref()'. Finally the status integer is returned and the GTK
	 * application exits */
	status = g_application_run(G_APPLICATION(app), argc, argv);
	g_object_unref(app);
	return status;
}