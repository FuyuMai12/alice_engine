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

The elements available in every game must be able to be split into distinct, non-intersecting simple cycles. That is, an element should counter exactly one other, that should counter exactly one different element, and so on until coming back to the first in the chain.

There will always be one default element: neutral (non-element). This is not countered by anything and doesn't counter anything either.

## Actions

An action (or "skill", as a more common yet less precise term) is something a character should do at each turn they have. There are mandatory and optional stats that one action should possess.
- Mandatory stats:
  - `target` (setting AoE center point, `self` for self, `front` to make the AoE at the front and touch the character, `back` to make it at the back and touching, or `[character_internal_name]` to specify the center at any character)
  - `aoe_type` (`rectangle` for rectangular, `circle` for circular, i.e. an ellipse AoE zone)
  - `x_radius` (any non-negative number, `-1` for infinity)
  - `y_radius` (ditto)
  - `speed` (action speed, deciding how much behind that action would take the character backward in the queue).
- Optional stats: TBD.

Our vision aims to have the actions only using the mandatory stats and the document-defined optional stats (i.e. cannot define custom names), and no overload programming is needed for the action behavior. This can change in the future.

The library will have two default skills: attack (basic attack) and defend (skip).

# Checklist

TBD, we have nothing yet.
