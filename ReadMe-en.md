# BulletHell Shooting Game with in-house Game Engine

**picture here**

## what is this project?

- Bullethell Shoot'em up game using original engine
- Using open-source Image Library "SDL2"
- Engine code in /Core/ directory

  
## Things to add
### Engine
 - memory control using **smart pointer**
 - JSONized level file & its file I/O in engine code
 - UI
 - audio
 
### Source : additional game content
 - bullet & enemy patterns
 - bossfight
 - pick-up items, upgrade
 - level design
- UI



## Game Framework Details

### Actor
- **Actor** is an object that can be placed or spawned in game such as Player, Enemy, Bullet, Background, etc.
- Each Actor can contain Component, which is an Implementation unit that provides Actor a basic action such as Movement, Collision, Sprite(in 2D), Player Input,  Weapon, etc.
- In order to add a new Actor in source, a programmer can add a new class that inherits base Actor class and extend it to its desired design.
- To use a hybrid of Actor-Component based and Inheritance-based Monolithic structure can guide a programmer to write a highly reusable code.

### Component
- **Component** is an Implementation unit that provides Actor a basic action such as Movement, Collision, Sprite(in 2D), Player Input,  Weapon, etc.

## How to Play

- TBD


## Core Structure of Engine
- UML here

- instructions of each /Core/ classes here

## Engine Workflow
- top-down diagram here
- instruction of /Core/Game here

## Source 
- TBD