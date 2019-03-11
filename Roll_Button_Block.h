class Button_Block {
public:
  GtkBox *Box;
  GtkLabel *result_label;
  int N_dice;
  int dice_type;
  int modifier;
  int result;
  std::string result_text;
  std::string button_block_title;

  GtkLabel *number_of_dice_label;
  GtkLabel *modifier_label;
  GtkEntry *dice_side_entry;

  Button_Block(GtkBox *Box, GtkLabel *result_label, int N_dice, int dice_type, int modifier, std::string button_block_title)
  : Box(Box)
  , result_label(result_label)
  , N_dice(N_dice)
  , dice_type(dice_type)
  , modifier(modifier)
  , result{0}
  , result_text{" -- "}
  , button_block_title(button_block_title)
  , number_of_dice_label{nullptr}
  , modifier_label{nullptr}
  , dice_side_entry{nullptr}
  {}

  Button_Block(GtkBox *Box, GtkLabel *result_label, int N_dice, int dice_type, int modifier)
  : Button_Block(Box, result_label, N_dice, dice_type, modifier, "Modifiable Roller") {}

  Button_Block(GtkBox *Box, GtkLabel *result_label)
  : Button_Block(Box, result_label, 1, 20, 0) {}

  Button_Block(GObject *Box, GObject *result_label)
  : Button_Block(GTK_BOX(Box), GTK_LABEL(result_label)) {}

  Button_Block(int N_dice,  int dice_type,  int modifier)
  : Button_Block(nullptr, nullptr, N_dice, dice_type, modifier) {}

  Button_Block()
  : Button_Block(1, 20, 0) {}

  void update_labels();
  void update_result();
  void increment_number_of_dice_up();
  void increment_number_of_dice_down();
  void increment_modifier_up();
  void increment_modifier_down();
  void roll();
  void construct_box();
};

// Button Functions

void B_Increment_Number_Of_Dice_Up(GtkWidget *widget, gpointer data);

void B_Increment_Number_Of_Dice_Down(GtkWidget *widget, gpointer data);

void B_Increment_Modifier_Up(GtkWidget *widget, gpointer data);

void B_Increment_Modifier_Down(GtkWidget *widget, gpointer data);

void B_Roll(GtkWidget *widget, gpointer data);

static void B_Get_Entry (GtkWidget *widget, gpointer data);

// Get Button Block From Builder


