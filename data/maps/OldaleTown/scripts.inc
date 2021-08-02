.set LOCALID_MART_EMPLOYEE, 2
.set LOCALID_FOOTPRINTS_MAN, 3
.set LOCALID_RIVAL, 4

OldaleTown_MapScripts:: @ 81E8EA2
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_OnTransition
	.byte 0

OldaleTown_OnTransition: @ 81E8EA8
	call Common_EventScript_SetupRivalGfxId
	setflag FLAG_VISITED_OLDALE_TOWN
	call_if_set FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_SetOldaleState
	end

@ This script seems pointless because nothing uses VAR_OLDALE_TOWN_STATE
OldaleTown_EventScript_SetOldaleState:: @ 81E8ECC
	setvar VAR_OLDALE_TOWN_STATE, 1
	return

OldaleTown_EventScript_BlockWestEntrance:: @ 81E8ED2
	setobjectxyperm LOCALID_FOOTPRINTS_MAN, 1, 11
	setobjectmovementtype LOCALID_FOOTPRINTS_MAN, MOVEMENT_TYPE_FACE_LEFT
	return

OldaleTown_EventScript_MoveMartEmployee:: @ 81E8EDE
	setobjectxyperm LOCALID_MART_EMPLOYEE, 13, 14
	setobjectmovementtype LOCALID_MART_EMPLOYEE, MOVEMENT_TYPE_FACE_DOWN
	return

OldaleTown_EventScript_CitySign:: @ 81E8EEA
	msgbox OldaleTown_Text_CitySign, MSGBOX_SIGN
	end

OldaleTown_EventScript_Girl:: @ 81E8EF3
	msgbox OldaleTown_Text_SavingMyProgress, MSGBOX_NPC
	end

OldaleTown_EventScript_MartEmployee:: @ 81E8EFC
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POTION_OLDALE, OldaleTown_EventScript_ExplainPotion
	goto_if_set FLAG_TEMP_1, OldaleTown_EventScript_ExplainPotion
	setflag FLAG_TEMP_1
	playbgm MUS_FOLLOW_ME, FALSE
	msgbox OldaleTown_Text_IWorkAtPokemonMart, MSGBOX_DEFAULT
	closemessage
	switch VAR_FACING
	case DIR_SOUTH, OldaleTown_EventScript_GoToMartSouth
	case DIR_NORTH, OldaleTown_EventScript_GoToMartNorth
	case DIR_EAST, OldaleTown_EventScript_GoToMartEast
	end

OldaleTown_EventScript_GoToMartSouth:: @ 81E8F47
	applymovement LOCALID_MART_EMPLOYEE, OldaleTown_Movement_EmployeeSouth
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerSouth
	waitmovement 0
	goto OldaleTown_EventScript_ExplainPokemonMart
	end

OldaleTown_EventScript_GoToMartNorth:: @ 81E8F5E
	applymovement LOCALID_MART_EMPLOYEE, OldaleTown_Movement_EmployeeNorth
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerNorth
	waitmovement 0
	goto OldaleTown_EventScript_ExplainPokemonMart
	end

OldaleTown_EventScript_GoToMartEast:: @ 81E8F75
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerEast
	applymovement LOCALID_MART_EMPLOYEE, OldaleTown_Movement_EmployeeEast
	waitmovement 0
	goto OldaleTown_EventScript_ExplainPokemonMart
	end

OldaleTown_EventScript_oldrodSign::
msgbox text_oldrodsign MSGBOX_SIGN
end

text_oldrodsign:
.string "Casa del Vecchio Marinaio$"

OldaleTown_EventScript_ExplainPokemonMart:: @ 81E8F8C
	msgbox OldaleTown_Text_ThisIsAPokemonMart, MSGBOX_DEFAULT
	giveitem ITEM_POTION
	compare VAR_RESULT, FALSE
	goto_if_eq OldaleTown_EventScript_BagIsFull
	msgbox OldaleTown_Text_PotionExplanation, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_POTION_OLDALE
	fadedefaultbgm
	release
	end

OldaleTown_EventScript_ExplainPotion:: @ 81E8FB9
	msgbox OldaleTown_Text_PotionExplanation, MSGBOX_DEFAULT
	release
	end

OldaleTown_EventScript_BagIsFull:: @ 81E8FC3
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	fadedefaultbgm
	release
	end

OldaleTown_Movement_EmployeeEast: @ 81E8FCE
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_down
	step_end

OldaleTown_Movement_EmployeeSouth: @ 81E8FD7
	walk_left
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_down
	step_end

OldaleTown_Movement_EmployeeNorth: @ 81E8FE2
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_down
	step_end

OldaleTown_Movement_Unknown1: @ 81E8FEB
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	walk_in_place_fastest_down
	step_end

OldaleTown_Movement_PlayerEast: @ 81E8FF9
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OldaleTown_Movement_PlayerSouth: @ 81E9001
	delay_16
	delay_16
	delay_16
	delay_16
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OldaleTown_Movement_PlayerNorth: @ 81E900B
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OldaleTown_Movement_Unknown2: @ 81E9013
	walk_left
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

EventScript_Lotad::
	lock
	faceplayer
	playmoncry SPECIES_LOTAD, 0
	msgbox Text_CryLotad, MSGBOX_DEFAULT
	waitmoncry
    closemessage
	release
	end

Text_CryLotad:
	.string "Lotad: Lotad!$"

EventScript_Mapcity::
    lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x022, Script_alreadyending
	msgbox Text_seinuovo MSGBOX_NPC
	playfanfare MUS_OBTAIN_ITEM
	giveitem ITEM_AMULET_COIN
    waitfanfare
    closemessage
	msgbox T_gb MSGBOX_DEFAULT
	closemessage
	setflag FLAG_UNUSED_0x022
  	closemessage
	release
	end

Text_seinuovo:
.string "I soldi non fanno la felicità,\n"
.string "però averne di più, potrebbe\l"
.string "aiutarti a comprare tutto ciò che\l"
.string "ti occorre, nelle lotte Pokémon!\l"
.string "Voglio regalarti questo strumento\l\l"
.string "incredibile che ho usato quando\l"
.string "ero più giovane. A me non serve\l"
.string "più, ormai. Ohohohoh!$"

Script_alreadyending::
lock
faceplayer
msgbox Text_gaveuthat MSGBOX_NPC
release
end

Text_gaveuthat:
.string "Mi sento sempre in dovere di\n"
.string "aiutare i giovani! Ohohohoh!$"

T_gb:
.string "Ora sì che le Lotte Pokémon\n"
.string "saranno più redditizie!$"

OldaleTown_EventScript_FootprintsMan:: @ 81E901F
	lock
	faceplayer
	msgbox Text_babyninja, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FOOTPRINTS_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Text_babyninja:
.string "Io e il mio Lotad, siamo grandi\n"
.string "amici. Sai che i Pokémon non ti\l"
.string "tradiranno mai?$"

OldaleTown_EventScript_BlockedPath:: @ 81E903F
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerStepBack
	applymovement LOCALID_FOOTPRINTS_MAN, OldaleTown_Movement_BackUp
	waitmovement 0
	msgbox OldaleTown_Text_WaitDontComeInHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FOOTPRINTS_MAN, OldaleTown_Movement_ReturnToOriginalPosition
	waitmovement 0
	releaseall
	end

OldaleTown_EventScript_NotBlockingPath:: @ 81E9066
	msgbox OldaleTown_Text_FinishedSketchingFootprints, MSGBOX_DEFAULT
	release
	end

OldaleTown_EventScript_Rival:: @ 81E9070
	lockall
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	setvar VAR_0x8009, 0
	goto OldaleTown_EventScript_ShowRivalMessage
	end

OldaleTown_EventScript_RivalTrigger1:: @ 81E9086
	lockall
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalApproachPlayer1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	setvar VAR_0x8009, 1
	goto OldaleTown_EventScript_ShowRivalMessage
	end

OldaleTown_EventScript_RivalTrigger2:: @ 81E90A6
	lockall
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalApproachPlayer2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	setvar VAR_0x8009, 1
	goto OldaleTown_EventScript_ShowRivalMessage
	end

OldaleTown_EventScript_RivalTrigger3:: @ 81E90C6
	lockall
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalApproachPlayer3
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	setvar VAR_0x8009, 1
	goto OldaleTown_EventScript_ShowRivalMessage
	end

OldaleTown_EventScript_ShowRivalMessage:: @ 81E90E6
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq OldaleTown_EventScript_ShowMayMessage
	compare VAR_RESULT, FEMALE
	goto_if_eq OldaleTown_EventScript_ShowBrendanMessage
	end

OldaleTown_EventScript_ShowMayMessage:: @ 81E90FE
	msgbox OldaleTown_Text_MayLetsGoBack, MSGBOX_DEFAULT
	goto OldaleTown_EventScript_RivalFinish
	end

OldaleTown_EventScript_ShowBrendanMessage:: @ 81E910C
	msgbox OldaleTown_Text_BrendanLetsGoBack, MSGBOX_DEFAULT
	goto OldaleTown_EventScript_RivalFinish
	end

OldaleTown_EventScript_RivalFinish:: @ 81E911A
	closemessage
	compare VAR_0x8009, 0
	call_if_eq OldaleTown_EventScript_DoExitMovement1
	compare VAR_0x8009, 1
	call_if_eq OldaleTown_EventScript_DoExitMovement2
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalExit
	waitmovement 0
	removeobject LOCALID_RIVAL
	setvar VAR_OLDALE_RIVAL_STATE, 2
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	releaseall
	end

OldaleTown_EventScript_DoExitMovement1:: @ 81E9148
	compare VAR_FACING, DIR_SOUTH
	goto_if_ne OldaleTown_EventScript_DoExitMovement2
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalExit
	waitmovement 0
	return

OldaleTown_EventScript_DoExitMovement2:: @ 81E915E
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_WatchRivalExit
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalExit
	waitmovement 0
	return

OldaleTown_Movement_RivalApproachPlayer1: @ 81E9170
	walk_left
	walk_left
	step_end

OldaleTown_Movement_RivalApproachPlayer2: @ 81E9173
	walk_left
	step_end

OldaleTown_Movement_RivalApproachPlayer3: @ 81E9175
	face_left
	step_end

OldaleTown_Movement_RivalExit: @ 81E9177
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

OldaleTown_Movement_WatchRivalExit: @ 81E917E
	delay_8
	delay_4
	walk_in_place_fastest_down
	step_end

OldaleTown_Movement_PlayerStepBack: @ 81E9182
	delay_8
	walk_right
	step_end

OldaleTown_Movement_BackUp: @ 81E9185
	walk_fast_up
	walk_in_place_fastest_left
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

OldaleTown_Movement_ReturnToOriginalPosition: @ 81E918B
	walk_down
	walk_left
	step_end

OldaleTown_Text_SavingMyProgress: @ 81E918E
	.string "I want to take a rest, so I'm saving my\n"
	.string "progress.$"

OldaleTown_Text_IWorkAtPokemonMart: @ 81E91C0
	.string "Hi!\n"
	.string "I work at a POKéMON MART.\p"
	.string "Can I get you to come with me?$"

OldaleTown_Text_ThisIsAPokemonMart: @ 81E91FD
	.string "This is a POKéMON MART.\n"
	.string "Just look for our blue roof.\p"
	.string "We sell a variety of goods including\n"
	.string "POKé BALLS for catching POKéMON.\p"
	.string "Here, I'd like you to have this as\n"
	.string "a promotional item.$"

OldaleTown_Text_PotionExplanation: @ 81E92AF
	.string "A POTION can be used anytime, so it's\n"
	.string "even more useful than a POKéMON CENTER\l"
	.string "in certain situations.$"

OldaleTown_Text_WaitDontComeInHere: @ 81E9313
	.string "Aaaaah! Wait!\n"
	.string "Please don't come in here.\p"
	.string "I just discovered the footprints of\n"
	.string "a rare POKéMON!\p"
	.string "Wait until I finish sketching\n"
	.string "them, okay?$"

OldaleTown_Text_DiscoveredFootprints: @ 81E939A
	.string "I just discovered the footprints of\n"
	.string "a rare POKéMON!\p"
	.string "Wait until I finish sketching\n"
	.string "them, okay?$"

OldaleTown_Text_FinishedSketchingFootprints: @ 81E93F8
	.string "I finished sketching the footprints of\n"
	.string "a rare POKéMON.\p"
	.string "But it turns out they were only my\n"
	.string "own footprints…$"

OldaleTown_Text_MayLetsGoBack: @ 81E9462
	.string "MAY: {PLAYER}{KUN}!\n"
	.string "Over here!\l"
	.string "Let's hurry home!$"

OldaleTown_Text_BrendanLetsGoBack: @ 81E948A
	.string "BRENDAN: I'm heading back to my dad's\n"
	.string "LAB now.\l"
	.string "{PLAYER}, you should hustle back, too.$"

OldaleTown_Text_CitySign: @ 81E94DA
	.string "Mascar\n"
	.string "{DOWN_ARROW} Percorso 1\l"
	.string "{UP_ARROW} Percorso 2\l"
	.string "{LEFT_ARROW} Percorso 3$"

OldaleTown_EventScript_Pokefan::
    lock
	faceplayer
	random 3
	switch VAR_RESULT
	case 0, Script_RandomOptionA
	case 1, Script_RandomOptionB
	case 2, Script_RandomOptionC
	end
	
Script_RandomOptionA::
	msgbox Text_RandomOptiona, MSGBOX_DEFAULT
	release
	end
	
Script_RandomOptionB::
	msgbox Text_RandomOptionb, MSGBOX_DEFAULT
	release
	end

Script_RandomOptionC::
	msgbox Text_RandomOptionc, MSGBOX_DEFAULT
	release
	end

Text_RandomOptiona:
.string "Timber è simile a Bell ma offre\n"
.string "più opportunità agli allenatori.\l"
.string "Puoi infatti, trovarci un Centro\l"
.string "Pokémon e un Poké Market!$"

Text_RandomOptionb:
.string "Ho sentito dire che è stata\n"
.string "scoperta una tipologia nuova di\l"
.string "Pokémon.$"

Text_RandomOptionc:
.string "E' curioso pensare che i migliori\n"
.string "allenatori della storia, abbiano\l"
.string "vinto il loro titolo in così\l"
.string "giovane età. I giovani sono così\l"
.string "talentuosi, ai giorni nostri!$"

OldaleTown_EventScript_Girly::
    lock
	faceplayer
	random 3
	switch VAR_RESULT
	case 0, Script_RandomOption11
	case 1, Script_RandomOption22
	case 2, Script_RandomOption33
	end

Script_RandomOption11::
	msgbox Text_RandomOption11, MSGBOX_DEFAULT
	release
	end

Script_RandomOption22::
	msgbox Text_RandomOption22, MSGBOX_DEFAULT
	release
	end

Script_RandomOption33::
	msgbox Text_RandomOption33, MSGBOX_DEFAULT
	release
	end

Text_RandomOption11:
.string "Chissà perché alcuni allenatori\n"
.string "vogliono a tutti i costi vincere\l"
.string "le medaglie. A me basta stare in\l"
.string "compagnia dei miei Pokémon.$"

Text_RandomOption22:
.string "Qui a Timber, non piove mai per\n"
.string "fortuna.$"

Text_RandomOption33:
.string "Si dice che ci sia un luogo,\n"
.string "accessibile solo a chi possiede\l"
.string "tutte le medaglie della regione.\l"
.string "Dev'essere molto pericoloso!$"
