class Character{
    enum Skills_List : long {
        // STR
        Athletics = 1,
        // DEX
        Acrobatics = 2,
        Sleight_Of_Hand = 4,
        Stealth = 8,
        // INT
        Arcana = 16,
        History = 32,
        Investigation = 64,
        Nature = 128,
        Religion = 256,
        // WIS
        Animal_Handling = 512,
        Insight = 1024,
        Medicine = 2048,
        Perception = 4096,
        Survival = 8192,
        // CHA
        Deception = 16384,
        Intimidation = 32768,
        Performance = 65536,
        Persuasion = 131072
    };
    enum Abilities {
        Str = 1,
        Dex = 2,
        Con = 4,
        Int = 8,
        Wis = 16,
        Cha = 32
    };
public:
  int STR;
  int DEX;
  int CON;
  int INT;
  int WIS;
  int CHA;
  int PROF;
  long Trained_Skills;
  void Add_Trained_Skill(std::string skill);
  void Remove_Trained_Skill(std::string skill);

  Character(int STR, int DEX, int CON, int INT, int WIS, int CHA, int PROF, std::vector<std::string> trained_skills)
  : STR{STR}
  , DEX{DEX}
  , CON{CON}
  , INT{INT}
  , WIS{WIS}
  , CHA{CHA}
  , PROF{PROF}
  , Trained_Skills(0)
  {
    for (std::string t : trained_skills)
    {
        Add_Trained_Skill(t);
    }
  }

  Character(int STR, int DEX, int CON, int INT, int WIS, int CHA, int PROF)
  : STR{STR}
  , DEX{DEX}
  , CON{CON}
  , INT{INT}
  , WIS{WIS}
  , CHA{CHA}
  , PROF{PROF}
  , Trained_Skills(0)
  {}

  Character()
  : Character(0, 0, 0, 0, 0, 0, 0) {}
};