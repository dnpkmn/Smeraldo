.set LOCALID_HO_OH, 1

NavelRock_Top_MapScripts:: @ 8269113
	map_script MAP_SCRIPT_ON_TRANSITION, NavelRock_Top_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, NavelRock_Top_OnResume
	.byte 0

NavelRock_Top_OnTransition: @ 826911E
	call_if_set FLAG_CAUGHT_HO_OH, NavelRock_Top_EventScript_HideHoOh
	call_if_unset FLAG_CAUGHT_HO_OH, NavelRock_Top_EventScript_TryShowHoOh
	end

NavelRock_Top_EventScript_HideHoOh:: @ 8269131
	setvar VAR_TEMP_1, 1
	setflag FLAG_HIDE_HO_OH
	return

NavelRock_Top_EventScript_TryShowHoOh:: @ 826913A
	setvar VAR_TEMP_1, 1
	goto_if_set FLAG_DEFEATED_HO_OH, Common_EventScript_NopReturn
	setvar VAR_TEMP_1, 0
	clearflag FLAG_HIDE_HO_OH
	return

NavelRock_Top_OnResume: @ 8269151
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, NavelRock_Top_EventScript_TryRemoveHoOh
	end

NavelRock_EventScript_Kami::
    lockall
	faceplayer
	playmoncry SPECIES_ARCEUS, 0
	msgbox Text_CryArceus, MSGBOX_DEFAULT
	waitmoncry
    closemessage
	release
	end

Text_CryArceus:
.string "Arceus: Arceus!"

NavelRock_EventScript_Kamifirsteventever::
     lockall
	 compare VAR_UNUSED_0x40A1, 0
	 goto_if_gt EventScript_doneitrdy
	 playbgm MUS_RG_ENCOUNTER_DEOXYS, TRUE
	 applymovement OBJ_EVENT_ID_PLAYER, m_salilescale
	 waitmovement 0
	 msgbox primotestkami MSGBOX_DEFAULT
	 closemessage
	 msgbox secondotestkami MSGBOX_DEFAULT
	 closemessage
	 msgbox terzotestkami MSGBOX_DEFAULT
	 closemessage
	 delay_16
	 delay_16
     delay_16
	 delay_16
	 delay_16
	 savebgm MUS_DUMMY
     fadedefaultbgm
	 warp MAP_INSIDE_OF_TRUCK, -1, 1, 2
	 waitstate
	 setvar VAR_UNUSED_0x40A1, 1
	 setvar VAR_UNUSED_0x409D, 1
	 releaseall
	 end

	 primotestkami:
	 .string "???: {PLAYER}. E' una visione reale\n"
	 .string "quella che vedi. Io sono Arceus,\l"
	 .string "il creatore di tutto ciò che vive.$"

     secondotestkami:
	.string "Arceus: Un grave pericolo, incombe\n"
	.string "su Ancar. Solo l'allenatore\l"
	.string "della profezia può impedire che\l"
	.string "il mondo venga distrutto da tale\l"
	.string "minaccia. Quell'allenatore sei\l"
	.string "tu, {PLAYER}. Trova la forza in\l"
	.string "te stesso e nei tuoi Pokémon,\l"
	.string "soltanto così potrai farcela.\l"
	.string "Questa missione sarà di vitale\l"
	.string "importanza per il tuo mondo.\l"
	.string "Se tu dovessi fallire, allora, il\l"
	.string "mondo non avrebbe più scampo.$"

    terzotestkami:
    .string "Arceus: Sono certo che riuscirai\n"
	.string "nel tuo intento, figlio mio.$"

	 m_salilescale:
	 walk_slow_up
	 walk_slow_up
	 walk_slow_up
	 walk_slow_up
	 walk_slow_up
	 walk_slow_up
	 walk_slow_up
	 walk_slow_up
	 walk_slow_up
	 walk_slow_up
	 walk_slow_up
	 walk_slow_up
	 walk_slow_up
	 walk_slow_up
	 walk_slow_up
	 walk_slow_up
	 walk_slow_up
	 walk_slow_up
	 walk_slow_up
	 walk_slow_up
	 walk_slow_up
	 step_end
	 
Text_Kami:
.string "Arceus: Arceus!$"

EventScript_goup::
lockall
compare VAR_UNUSED_0x409D, 0
goto_if_gt EventScript_doneitrdy
msgbox Testo_proibito MSGBOX_DEFAULT
closemessage
applymovement OBJ_EVENT_ID_PLAYER, spostasu
waitmovement 0
release
end

Testo_proibito:
.string "Una voce sussurra: Sali le scale.$"

spostasu:
walk_up
step_end

EventScript_doneitrdy::
releaseall
end

NavelRock_Top_EventScript_TryRemoveHoOh:: @ 826915B
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject LOCALID_HO_OH
	return

NavelRock_Top_EventScript_HoOh:: @ 826916F
	lockall
	setvar VAR_TEMP_1, 1
	special SpawnCameraObject
	setvar VAR_0x8004, 3  @ num loops
	setvar VAR_0x8005, 35 @ delay
	special LoopWingFlapSE
	applymovement LOCALID_HO_OH, NavelRock_Top_Movement_HoOhAppear
	applymovement OBJ_EVENT_ID_CAMERA, NavelRock_Top_Movement_CameraPanUp
	waitmovement 0
	delay 50
	setweather WEATHER_NONE
	doweather
	waitse
	playmoncry SPECIES_HO_OH, 2
	delay 30
	waitmoncry
	delay 60
	setvar VAR_0x8004, 3  @ num loops
	setvar VAR_0x8005, 35 @ delay
	special LoopWingFlapSE
	applymovement OBJ_EVENT_ID_CAMERA, NavelRock_Top_Movement_CameraPanDown
	applymovement LOCALID_HO_OH, NavelRock_Top_Movement_HoOhApproach
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_0x8004, SPECIES_HO_OH
	setvar VAR_0x8005, 70 @ level
	setvar VAR_0x8006, ITEM_NONE
	special CreateEventLegalEnemyMon
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_LAST_TALKED, LOCALID_HO_OH
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq NavelRock_Top_EventScript_DefeatedHoOh
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq NavelRock_Top_EventScript_RanFromHoOh
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq NavelRock_Top_EventScript_RanFromHoOh
	setflag FLAG_CAUGHT_HO_OH
	releaseall
	end

NavelRock_Top_EventScript_DefeatedHoOh:: @ 8269217
	setflag FLAG_DEFEATED_HO_OH
	setvar VAR_0x8004, SPECIES_HO_OH
	goto Common_EventScript_LegendaryFlewAway
	end

NavelRock_Top_EventScript_RanFromHoOh:: @ 8269225
	setvar VAR_0x8004, SPECIES_HO_OH
	goto Common_EventScript_LegendaryFlewAway
	end

NavelRock_Top_Movement_CameraPanUp: @ 8269230
	walk_up
	walk_up
	walk_up
	step_end

NavelRock_Top_Movement_CameraPanDown: @ 8269234
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	step_end

NavelRock_Top_Movement_HoOhApproach: @ 826923A
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_down
	delay_16
	delay_16
	step_end

NavelRock_Top_Movement_HoOhAppear: @ 8269243
	delay_16
	delay_16
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	step_end
