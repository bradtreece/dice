#include <gtk/gtk.h>
#include <cstring>
#include <string>
#include "Roll_Button_Block.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


static void print_hello (GtkWidget *widget,
		         gpointer data)
{
  g_print ("Hello Brad\n");
}

int main (int argc, char *argv[])
{
  GtkBuilder *builder;
  GObject *window;
  GObject *box;
  GObject *button;
  GObject *label;
  GError *error = NULL;

  gtk_init (&argc, &argv);
  srand (time(0));

  // Construct a GtkBuilder instance and load our UI descricptrion 
  builder = gtk_builder_new();
  if (gtk_builder_add_from_file (builder, "./builder2.ui", &error) == 0)
  {
    g_printerr ("Error loading file: %s\n", error->message);
    g_clear_error (&error);
    return 1;
  }
  GtkCssProvider *cssProvider = gtk_css_provider_new();
  gtk_css_provider_load_from_path(cssProvider, "theme.css", NULL);
  gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(cssProvider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);


  // Connect signal handlers to the constructed widgets.
  window = gtk_builder_get_object (builder, "window");
  g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

  box = gtk_builder_get_object (builder, "background_box");
  gtk_widget_set_name(GTK_WIDGET(box), "background_box");

  label = gtk_builder_get_object (builder, "result");
  gtk_widget_set_name(GTK_WIDGET(label), "result");

  box = gtk_builder_get_object (builder, "roller_box");
  gtk_widget_set_vexpand (GTK_WIDGET(box), FALSE);
  gtk_widget_set_valign (GTK_WIDGET(box), GTK_ALIGN_END);
  Button_Block bb = Button_Block(box, label);
  bb.construct_box();

  box = gtk_builder_get_object (builder, "roller_box2");
  gtk_widget_set_vexpand (GTK_WIDGET(box), FALSE);
  gtk_widget_set_valign (GTK_WIDGET(box), GTK_ALIGN_END);
  Button_Block bb2 = Button_Block(box, label);
  bb2.construct_box();

  button = gtk_builder_get_object (builder, "quit");
  gtk_widget_set_name(GTK_WIDGET(button), "quit");
  gtk_button_set_label(GTK_BUTTON(button), "\n    Quit    \n");
  g_signal_connect (button, "clicked", G_CALLBACK (gtk_main_quit), NULL);
  gtk_widget_set_hexpand (GTK_WIDGET(button), FALSE);
  gtk_widget_set_halign (GTK_WIDGET(button), GTK_ALIGN_CENTER);
  gtk_widget_set_vexpand (GTK_WIDGET(button), FALSE);
  gtk_widget_set_valign (GTK_WIDGET(button), GTK_ALIGN_CENTER);


  gtk_main ();

  return 0;
}
