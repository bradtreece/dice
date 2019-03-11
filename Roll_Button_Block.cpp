#include <gtk/gtk.h>
#include <cstring>
#include <string>
#include "Roll_Button_Block.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

void Button_Block::update_labels()
{
  gtk_label_set_markup(number_of_dice_label, (std::to_string(N_dice)+"d"+std::to_string(dice_type)).c_str());
  gtk_label_set_markup(modifier_label, (std::to_string(modifier)).c_str());
}

void Button_Block::update_result()
{
  gtk_label_set_markup(result_label, result_text.c_str());
}

void Button_Block::increment_number_of_dice_up()
{
  N_dice += 1;
  update_labels();
}

void Button_Block::increment_number_of_dice_down()
{
  N_dice -= 1;
  update_labels();
}

void Button_Block::increment_modifier_up()
{
  modifier += 1;
  update_labels();
}

void Button_Block::increment_modifier_down()
{
  modifier -= 1;
  update_labels();
}

void Button_Block::roll()
{
  int r;

  result = 0;
  result_text = "";
  for (int i=0; i<N_dice; i++)
  {
    r = rand()%dice_type + 1;
    result_text += std::to_string(r) + "+";
    result += r;
  }
  result += modifier;
  result_text += "("+std::to_string(modifier)+")="+std::to_string(result);
  update_result();
}

void Button_Block::construct_box()
{
    if (!Box)
    {
        printf("\nNo box was specified to contain the button block.\n");
        if (!result_label)
        {
            printf("Also, no label was specified to connect to for printing results.\n");
        }
        return;
    } else if (!result_label)
    {
        printf("No label was specified to connect to for printing results.\n");
        return;
    } else {

        GtkWidget *box;
        GtkWidget *Grid;
        GtkWidget *VBox;
        GtkWidget *button;
        GtkWidget *label;
        GtkWidget *mod_label;
        GtkWidget *entry;
        GtkWidget *frame;

        frame = gtk_frame_new(button_block_title.c_str());
        gtk_widget_set_name(frame, "roller_box");
        gtk_frame_set_shadow_type(GTK_FRAME(frame), GTK_SHADOW_NONE);
        gtk_container_set_border_width (GTK_CONTAINER (frame), 5);
        gtk_box_pack_start(Box, frame, FALSE, FALSE, 0);
//

        Grid = gtk_grid_new();
        gtk_container_add (GTK_CONTAINER (frame), Grid);
//

        VBox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
        gtk_grid_attach(GTK_GRID(Grid), VBox, 0, 0, 1, 1);
        button = gtk_button_new_with_label ("Roll");
        gtk_widget_set_name(button, "roller_button");
        gtk_box_pack_start(GTK_BOX(VBox), button, TRUE, TRUE, 0);
        g_signal_connect (button, "clicked", G_CALLBACK (B_Roll), this);
        gtk_widget_show (button);
        gtk_widget_show (VBox);
//

        VBox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
        gtk_grid_attach(GTK_GRID(Grid), VBox, 1, 0, 1, 1);
        button = gtk_button_new_with_label ("+");
        gtk_widget_set_name(button, "roller_button");
        gtk_box_pack_start(GTK_BOX(VBox), button, TRUE, TRUE, 0);
        g_signal_connect (button, "clicked", G_CALLBACK (B_Increment_Number_Of_Dice_Up), this);
        gtk_widget_show (button);

        button = gtk_button_new_with_label ("-");
        gtk_widget_set_name(button, "roller_button");
        gtk_box_pack_start(GTK_BOX(VBox), button, TRUE, TRUE, 0);
        g_signal_connect (button, "clicked", G_CALLBACK (B_Increment_Number_Of_Dice_Down), this);
        gtk_widget_show (button);

        button = gtk_button_new_with_label ("+");
        gtk_widget_set_name(button, "roller_button");
        gtk_box_pack_start(GTK_BOX(VBox), button, TRUE, TRUE, 0);
        g_signal_connect (button, "clicked", G_CALLBACK (B_Increment_Modifier_Up), this);
        gtk_widget_show (button);

        button = gtk_button_new_with_label ("-");
        gtk_widget_set_name(button, "roller_button");
        gtk_box_pack_start(GTK_BOX(VBox), button, TRUE, TRUE, 0);
        g_signal_connect (button, "clicked", G_CALLBACK (B_Increment_Modifier_Down), this);
        gtk_widget_show (button);
        gtk_widget_show (VBox);
//

        VBox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
        gtk_grid_attach(GTK_GRID(Grid), VBox, 2, 0, 1, 1);
        
        label = gtk_label_new ("#Dice");
        number_of_dice_label = GTK_LABEL (label);
        gtk_box_pack_start(GTK_BOX(VBox), label, TRUE, TRUE, 0);
        gtk_widget_show (label);
        
        label = gtk_label_new ("Mod");
        modifier_label = GTK_LABEL (label);
        gtk_box_pack_start(GTK_BOX(VBox), label, TRUE, TRUE, 0);
        gtk_widget_show (label);
        gtk_widget_show (VBox);
//

        entry = gtk_entry_new ();
        gtk_widget_set_name(entry, "roller_entry");
        dice_side_entry = GTK_ENTRY (entry);
        gtk_entry_set_max_length (GTK_ENTRY(entry), 3);
        gtk_entry_set_width_chars (GTK_ENTRY(entry), 5);
        gtk_grid_attach(GTK_GRID(Grid), entry, 0, 1, 1, 1);
        gtk_widget_show (entry);

        button = gtk_button_new_with_label ("Update Dice Sides");
        gtk_widget_set_name(button, "roller_button");
        gtk_grid_attach(GTK_GRID(Grid), button, 1, 1, 2, 1);
        g_signal_connect (button, "clicked", G_CALLBACK (B_Get_Entry), this);
        gtk_widget_show (button);
//        

        gtk_widget_show (Grid);
        gtk_widget_show (frame);
        

        update_labels();

    }

    return;
}

// Button Functions

void B_Get_Entry (GtkWidget *widget, gpointer data)
{
  Button_Block *bb = (Button_Block *) data;
  const gchar *text = gtk_entry_get_text (bb->dice_side_entry);
  try
  {
      bb->dice_type = std::stoi(text);

  } catch (...)
  {
      printf("\nNot An Integer Number Of Sides.\n");
  }

  gtk_entry_set_text(bb->dice_side_entry, "");
  bb->update_labels();
}

void B_Increment_Number_Of_Dice_Up(GtkWidget *widget, gpointer data)
{
  Button_Block *bb = (Button_Block *) data;
  bb->increment_number_of_dice_up();
}

void B_Increment_Number_Of_Dice_Down(GtkWidget *widget, gpointer data)
{
  Button_Block *bb = (Button_Block *) data;
  bb->increment_number_of_dice_down();
}

void B_Increment_Modifier_Up(GtkWidget *widget, gpointer data)
{
  Button_Block *bb = (Button_Block *) data;
  bb->increment_modifier_up();
}

void B_Increment_Modifier_Down(GtkWidget *widget, gpointer data)
{
  Button_Block *bb = (Button_Block *) data;
  bb->increment_modifier_down();
}

void B_Roll(GtkWidget *widget, gpointer data)
{
  Button_Block *bb = (Button_Block *) data;
  bb->roll();
}