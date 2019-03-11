#include <cstring>
#include <string>
#include <vector>
#include "Character_Sheet.h"

void Character::Add_Trained_Skill(std::string skill)
{
  if (skill == "acrobatics") {
    Trained_Skills |= Acrobatics;
  } else if (skill == "arcana") {
    Trained_Skills |= Arcana;
  } else if (skill == "animal handling") {
    Trained_Skills |= Animal_Handling;
  } else if (skill == "athletics") {
    Trained_Skills |= Athletics;
  } else if (skill == "deception") {
    Trained_Skills |= Deception;
  } else if (skill == "history") {
    Trained_Skills |= History;
  } else if (skill == "insight") {
    Trained_Skills |= Insight;
  } else if (skill == "intimidation") {
    Trained_Skills |= Intimidation;
  } else if (skill == "investigation") {
    Trained_Skills |= Investigation;
  } else if (skill == "medicine") {
    Trained_Skills |= Medicine;
  } else if (skill == "nature") {
    Trained_Skills |= Nature;
  } else if (skill == "perception") {
    Trained_Skills |= Perception;
  } else if (skill == "performance") {
    Trained_Skills |= Performance;
  } else if (skill == "persuasion") {
    Trained_Skills |= Persuasion;
  } else if (skill == "religion") {
    Trained_Skills |= Religion;
  } else if (skill == "sleight of hand") {
    Trained_Skills |= Sleight_Of_Hand;
  } else if (skill == "stealth") {
    Trained_Skills |= Stealth;
  } else if (skill == "survival") {
    Trained_Skills |= Survival;
  } else {
    printf("\nUnrecognized Skill: \"%s\". Please use all lowercase letters, separate words using spaces, remove unneccesary characters, and check your spelling.\n", skill.c_str());
    return;
  }
  return;
}

void Character::Remove_Trained_Skill(std::string skill)
{
  if (skill == "acrobatics") {
    Trained_Skills &= ~Acrobatics;
  } else if (skill == "arcana") {
    Trained_Skills &= ~Arcana;
  } else if (skill == "animal handling") {
    Trained_Skills &= ~Animal_Handling;
  } else if (skill == "athletics") {
    Trained_Skills &= ~Athletics;
  } else if (skill == "deception") {
    Trained_Skills &= ~Deception;
  } else if (skill == "history") {
    Trained_Skills &= ~History;
  } else if (skill == "insight") {
    Trained_Skills &= ~Insight;
  } else if (skill == "intimidation") {
    Trained_Skills &= ~Intimidation;
  } else if (skill == "investigation") {
    Trained_Skills &= ~Investigation;
  } else if (skill == "medicine") {
    Trained_Skills &= ~Medicine;
  } else if (skill == "nature") {
    Trained_Skills &= ~Nature;
  } else if (skill == "perception") {
    Trained_Skills &= ~Perception;
  } else if (skill == "performance") {
    Trained_Skills &= ~Performance;
  } else if (skill == "persuasion") {
    Trained_Skills &= ~Persuasion;
  } else if (skill == "religion") {
    Trained_Skills &= ~Religion;
  } else if (skill == "sleight of hand") {
    Trained_Skills &= ~Sleight_Of_Hand;
  } else if (skill == "stealth") {
    Trained_Skills &= ~Stealth;
  } else if (skill == "survival") {
    Trained_Skills &= ~Survival;
  } else {
    printf("\nUnrecognized Skill: \"%s\". Please use all lowercase letters, separate words using spaces, remove unneccesary characters, and check your spelling.\n", skill.c_str());
  }
}