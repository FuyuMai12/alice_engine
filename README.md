# Alice Engine, by Alice Ngo

_Truly inspired by a certain engine from a turn-based RPG, trying to be an universal engine/library that would support the core combat mechanic of that and another certain turn-based RPG._

# Features

**Disclaimers:** The scope of this project is not finalized.

This project aims to create a backbone library to make any 2D turn-based RPGs functional.

## Characters

First and foremost, a character by itself should have these basic stats: health, energy/mana, physical attack, physical defense, magical attack, magical defense, speed, luck.
- The first six stats are self-explanatory. Scalings for attack and defense are TBD.
- Luck should affect any RNGable events (ailments, crits, etc.). Scalings are TBD.
- Speed should determine the turn order in a combat. Scalings from base stats and skill stats for speed are TBD.

In a combat, characters should be placed on a 2D plane, with rules customizable for each game (even the seemingly 1D option like that certain 2nd RPG could be properly mapped into a 2D plane). Each character should have an x-coordinate, a y-coordinate, and a directional 2D vector. The coordinates are important for some certain features later on.

## Elements

The elements available in every game must be able to be split into distinct, non-intersecting simple cycles. That is, an element should counter exactly one other, that should counter exactly one different element, and so on until coming back to the first in the chain. The counter/countered mechanics could be implemented by adding two float coefficient constants: each constant multiply the effect of countering or being countered. As a result, the countering constant must not be lower than `1.0`, and the countered constant must not be higher than `1.0` as well.

There will always be one default element: neutral (non-element). This is not countered by anything and doesn't counter anything either.

Elements are independent with damage type (physical/magical): there can be any elemental physical damage, and also non-elemental magical damage, though how counter-intuitive those ideas might sound.

## Actions

An action (or "skill", as a more common yet less precise term) is something a character should do at each turn they have. There are mandatory and optional stats that one action should possess.
- Mandatory stats:
  - `target` (setting AoE center point, `self` for self, `front` to make the AoE at the front and touch the character, `back` to make it at the back and touching, or `[character_internal_name]` to specify the center at any character).
  - `aoe_type` (`rectangle` for rectangular, `circle` for circular, i.e. an ellipse AoE zone).
  - `x_radius` (any non-negative number, `-1` for infinity).
  - `y_radius` (ditto).
  - `speed` (action speed, deciding how much behind that action would take the character backward in the queue).
- Optional stats:
  - `args`: a mapping of custom arguments that should be used for specific behaviors.
- Mandatory behavioral functions:
  - `rollback`: undo all effects being active by the action.
  - `passive`: proc exactly one upon learning/upgrading the action - this is used for purely passive actions (i.e. stat sticks).
  - `active`: proc when being used as an active action.
  - `on_strike`: proc when attacking a target (might be redundant with `active`, might be not).
  - `on_struck`: proc when being attacked (i.e. reflecting damage actions).
 
***Issues:*** This idea cannot yet implement a certain skill in that certain 2nd RPG, where the user "hides" in their first turn and then backstab in their second one.

The library will have two default actions: attack (basic attack) and defend (skip). They are implemented as inherited class of the action base class.

# Checklist

TBD, we have nothing yet.
