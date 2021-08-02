.set LOCALID_MOM, 1
.set LOCALID_RIVAL_MOM, 4
.set LOCALID_RIVAL, 7

LittlerootTown_BrendansHouse_1F_MapScripts:: @ 81F7755
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_BrendansHouse_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_BrendansHouse_1F_OnFrame
	.byte 0

LittlerootTown_BrendansHouse_1F_OnLoad: @ 81F7765
	compare VAR_LITTLEROOT_INTRO_STATE, 6
	call_if_lt LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual
	end

LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes:: @ 81F777A
	setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, 1
	setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, 1
	return

LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual:: @ 81F778D
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual
	return

LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual:: @ 81F779A
	setmetatile 3, 7, METATILE_BrendansMaysHouse_BookOnTable, 1
	return

LittlerootTown_BrendansHouse_1F_OnTransition: @ 81F77A4
	compare VAR_LITTLEROOT_INTRO_STATE, 3
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor
	compare VAR_LITTLEROOT_INTRO_STATE, 5
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs
	compare VAR_LITTLEROOT_INTRO_STATE, 6
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV
	compare VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 0
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_MoveMomDadEevee @ 81F77C6
	end

	LittlerootTown_BrendansHouse_1F_EventScript_MoveMomDadEevee:: @ 81F77C6
	setobjectxyperm 5, 8, 4
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_LEFT
	setobjectxyperm LOCALID_MOM, 7, 4
    setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_RIGHT
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs:: @ 81F77C6
	setobjectxyperm LOCALID_MOM, 8, 4
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV:: @ 81F77D2
	setobjectxyperm LOCALID_MOM, 4, 5
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor:: @ 81F77DE
	setobjectxyperm LOCALID_MOM, 9, 8
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

@ Many of the below scripts have no gender check because they assume youre in the correct house
@ The below SS Ticket script uses Mays house state by accident(?), but theyre both set identically after the intro
LittlerootTown_BrendansHouse_1F_OnFrame: @ 81F77EA
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 0, LittlerootTown_BrendansHouse_1F_EventoEevee
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 3, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
	.2byte 0

LittlerootTown_BrendansHouse_1F_EventoEevee::
lockall
compare VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 7,
goto_if_eq EventScript_Endd
playbgm MUS_LITTLEROOT, TRUE
playse SE_PIN
applymovement OBJ_EVENT_ID_PLAYER, Movement_1
waitmovement 0
applymovement 1, Movement_2  
applymovement 5, Movement_2
waitmovement 0
msgbox Text_1 MSGBOX_DEFAULT
closemessage
msgbox Text_2 MSGBOX_DEFAULT
closemessage
applymovement OBJ_EVENT_ID_PLAYER, Movement_3
waitmovement 0
msgbox Text_3, MSGBOX_DEFAULT
closemessage
applymovement 1, Movement_4
waitmovement 0
msgbox Text_4, MSGBOX_DEFAULT
closemessage
applymovement 5, Movement_5
waitmovement 0
msgbox Text_5, MSGBOX_DEFAULT
closemessage
applymovement 1, Movement_6
applymovement 5, Movement_6
waitmovement 0
msgbox Text_6, MSGBOX_DEFAULT
closemessage
applymovement 1, Movement_4
waitmovement 0
msgbox Text_7, MSGBOX_DEFAULT
closemessage
applymovement 5, Movement_5
waitmovement 0
msgbox Text_8, MSGBOX_DEFAULT
closemessage
applymovement 5, Movement_7
applymovement 1, Movement_6
waitmovement 0
msgbox Text_9 MSGBOX_DEFAULT
closemessage
msgbox Text_10, MSGBOX_DEFAULT
closemessage
playfanfare MUS_OBTAIN_ITEM
givemon SPECIES_EEVEE, 5, ITEM_SITRUS_BERRY
msgbox Text_ReceivedEevee, MSGBOX_DEFAULT
waitfanfare
msgbox Text_NicknameEevee, MSGBOX_YESNO
compare VAR_RESULT, YES
call_if_eq NicknamingEevee
msgbox Text_11, MSGBOX_DEFAULT
closemessage
applymovement 5, Movement_8
waitmovement 0
applymovement OBJ_EVENT_ID_PLAYER, Movement_6
applymovement 1, Movement_6
waitmovement 0
msgbox Text_12, MSGBOX_DEFAULT
closemessage
applymovement 5, Movement_9
waitmovement 0
removeobject 5
applymovement 1, Movement_towardsplayer
applymovement OBJ_EVENT_ID_PLAYER, Move_Faceup
waitmovement 0
msgbox Text_runningshoes, MSGBOX_DEFAULT
closemessage
playfanfare MUS_OBTAIN_ITEM
msgbox Text_Obtainedshoes, MSGBOX_DEFAULT
waitfanfare
closemessage
msgbox Text_runningshoestutorial, MSGBOX_DEFAULT
closemessage
msgbox Text_ending, MSGBOX_DEFAULT
closemessage
savebgm MUS_DUMMY
fadedefaultbgm
setflag FLAG_RECEIVED_RUNNING_SHOES
setflag FLAG_SYS_B_DASH
setvar VAR_UNUSED_0x408B 1
setflag FLAG_SYS_POKEMON_GET
setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 7
setflag FLAG_HIDE_PLAYERS_HOUSE_DAD
releaseall
end

Text_Obtainedshoes:
.string "{PLAYER} riceve le Scarpe da Corsa!$"

Text_ending:
.string "Buon viaggio, tesoro!$"

Text_runningshoes:
.string "Mamma: {PLAYER}, non è mai facile\n"
.string "per una madre, vedere il figlio\l"
.string "andare via di casa. Però, so\l"
.string "quanto hai desiderato avere un\l"
.string "Pokémon tutto tuo! Vorrei\l"
.string "almeno mi venissi a trovare ogni\l"
.string "tanto. Prima che tu vada via,\l"
.string "voglio anche io farti un regalo.\l"
.string "Sono delle Scarpe da Corsa. Con\l"
.string "queste, potrai andare ovunque, in\l"
.string "men che non si dica!$"

Text_runningshoestutorial:
.string "E' il manuale per le scarpe da\n"
.string "corsa! Vediamo cosa c'è scritto..\p"
.string "Le Scarpe da Corsa per andare\l"
.string "veloce come il vento! O quasi..\n"
.string "Premere B per correre!$"

Movement_towardsplayer:
walk_right
walk_down
step_end

Move_Faceup:
face_up
step_end

NicknamingEevee::
setvar VAR_0x8004, 0
fadescreen 1
special ChangePokemonNickname
waitstate
return

EventScript_Endd::
releaseall
end

Movement_1:
emote_exclamation_mark
step_end

Movement_2:
face_down
emote_exclamation_mark
step_end

Movement_3:
walk_up
walk_up
step_end

Movement_4:
face_right
step_end

Movement_5:
face_left
step_end

Movement_6:
face_down
step_end

Movement_7:
walk_down
step_end

Movement_8:
walk_right
walk_down
walk_down
walk_left
face_up
step_end

Movement_9:
walk_down
step_end

Text_1:
.string "Mamma: Tesoro! Bentornato!$"

Text_2:
.string "Papà: Ciao {PLAYER}. Bentornato.$"

Text_3:
.string "Papà: Dov'eri andato di bello?$"

Text_4:
.string "Mamma: E' andato a presentarsi dai\n"
.string "vicini di casa. Un'altra famiglia\l"
.string "si è trasferita come noi, proprio\l"
.string "oggi, qui a Bell.$"

Text_5:
.string "Ah, capisco.$"

Text_6:
.string "Papà: Bene, io devo andare via\n"
.string "adesso. Cercherò di tornare il\l"
.string "prima possibile.$"

Text_7:
.string "Mamma: Ma come? Sei appena\n"
.string "tornato..$"

Text_8:
.string "Papà: Hai ragione cara. Tuttavia,\n"
.string "devo incontrare una certa\l"
.string "persona per parlare di affari. A\l"
.string "quel punto, tornerò a casa, per\l"
.string "una meritata vacanza. Ahahah!$"

Text_9:
.string "Papà: {PLAYER}. Oggi è il tuo\n"
.string "compleanno. Per questo, non\l"
.string "potevo non farti un regalo.$"

Text_10:
.string "Papà: Durante il mio ultimo\n"
.string "viaggio, ho trovato un cucciolo di\l"
.string "Eevee, probabilmente abbandonato\l"
.string "dal suo allenatore. Non potevo\l"
.string "lasciarlo lì senza fare nulla.\l"
.string "Questo Pokémon ha bisogno di un\l"
.string "allenatore che lo tratti bene.\l"
.string "Questo è il mio regalo per te,\l"
.string "{PLAYER}.$"

Text_ReceivedEevee:
.string "{PLAYER} ha ricevuto Eevee!$"

Text_NicknameEevee:
.string "Vuoi dare un soprannome ad Eevee?$"

Text_11:
.string "Papà: Non ho mai visto un Pokémon\n"
.string "così felice. Sono sicuro che con\l"
.string "te, è in ottime mani.$"

Text_12:
.string "Papà: A presto!$"

Text_posteevee:
.string "Mamma: Che bel regalo di\n"
.string "compleanno! Tuo padre è sempre\l"
.string "molto indaffarato. Capisco se vuoi\l"
.string "metterti in viaggio con il tuo\l"
.string "Pokémon. Mi raccomando {PLAYER},\l"
.string "fai sempre attenzione.$"

Event_vicini::
lock
faceplayer
msgbox PlayersHouse_1F_Text_DidYouMeetProfBirch MSGBOX_DEFAULT
release
end

PlayersHouse_1F_EventScript_Mom2::
checkflag FLAG_UNUSED_0x023
goto_if_unset FLAG_UNUSED_0x023, LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock
checkflag FLAG_SYS_POKEMON_GET
goto_if_unset FLAG_SYS_POKEMON_GET, Event_vicini
goto_if_set FLAG_SYS_POKEMON_GET, Event_posteevee
msgbox Text_posteevee MSGBOX_DEFAULT
release
end

Event_posteevee::
lock
faceplayer
msgbox Text_posteevee MSGBOX_DEFAULT
release
end

LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock:: @ 81F7814
	lockall
	msgbox PlayersHouse_1F_Text_GoSetTheClock, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	applymovement LOCALID_MOM, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	waitmovement 0
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, 255, 7, 1
	waitstate
	setflag FLAG_UNUSED_0x023
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs: @ 81F783A
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn:: @ 81F783C
	lockall
	setvar VAR_0x8004, LOCALID_MOM
	setvar VAR_0x8005, MALE
	goto PlayersHouse_1F_EventScript_EnterHouseMovingIn
	end

LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport:: @ 81F784D
	lockall
	setvar VAR_0x8004, MALE
	setvar VAR_0x8005, LOCALID_MOM
	goto PlayersHouse_1F_EventScript_PetalburgGymReportMale
	end

LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor:: @ 81F785E
	lockall
	playse SE_PIN
	applymovement LOCALID_RIVAL_MOM, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL_MOM, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	applymovement LOCALID_RIVAL_MOM, LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach
	waitmovement 0
	special GetRivalSonDaughterString
	msgbox RivalsHouse_1F_Text_OhYoureTheNewNeighbor, MSGBOX_DEFAULT
	setflag FLAG_MET_RIVAL_MOM
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach: @ 81F789C
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_GoSeeRoom:: @ 81F78A3
	lockall
	setvar VAR_0x8004, LOCALID_MOM
	setvar VAR_0x8005, MALE
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	goto PlayersHouse_1F_EventScript_MomGoSeeRoom
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival0:: @ 81F78BE
	lockall
	setvar VAR_0x8008, 0
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival1:: @ 81F78CA
	lockall
	setvar VAR_0x8008, 1
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival2:: @ 81F78D6
	lockall
	setvar VAR_0x8008, 2
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival:: @ 81F78E2
	playse SE_EXIT
	delay 10
	addobject LOCALID_RIVAL
	delay 30
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	compare VAR_0x8008, 1
	call_if_ne LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	compare VAR_0x8008, 0
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0
	compare VAR_0x8008, 1
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1
	compare VAR_0x8008, 2
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2
	msgbox RivalsHouse_1F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	compare VAR_0x8008, 0
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0
	compare VAR_0x8008, 1
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1
	compare VAR_0x8008, 2
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2
	playse SE_EXIT
	removeobject LOCALID_RIVAL
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	delay 30
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan:: @ 81F7981
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0:: @ 81F798C
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1:: @ 81F7997
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2:: @ 81F79A2
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0: @ 81F79AD
	walk_in_place_fastest_left
	walk_left
	walk_in_place_fastest_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1: @ 81F79B5
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2: @ 81F79B9
	walk_in_place_fastest_right
	walk_right
	walk_in_place_fastest_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0:: @ 81F79C1
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1:: @ 81F79D3
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2:: @ 81F79E5
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0: @ 81F79F7
	delay_16
	delay_8
	walk_in_place_fastest_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1: @ 81F79FB
	delay_16
	delay_8
	walk_in_place_fastest_right
	delay_16
	delay_16
	walk_in_place_fastest_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2: @ 81F7A02
	delay_16
	delay_8
	walk_in_place_fastest_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0: @ 81F7A06
	walk_in_place_fastest_right
	walk_right
	walk_in_place_fastest_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1: @ 81F7A0C
	walk_in_place_fastest_right
	walk_right
	walk_in_place_fastest_up
	walk_up
	walk_up
	walk_in_place_fastest_left
	walk_left
	walk_in_place_fastest_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2: @ 81F7A16
	walk_in_place_fastest_left
	walk_left
	walk_in_place_fastest_up
	walk_up
	walk_up
	step_end

PlayersHouse_1F_Text_IsntItNiceInHere: @ 81F7A1C
	.string "Mamma: Vedi, {PLAYER}?\n"
	.string "Non è carina?$"

PlayersHouse_1F_Text_MoversPokemonGoSetClock: @ 81F7A46
	.string "Ci penseranno i Pokémon a\n"
	.string "sistemare le nostre valigie.\l"
	.string "Viva i Pokémon!\p"
	.string "{PLAYER}, la tua stanza è sopra.\n"
	.string "Dagli un'occhiata, caro!\p"
	.string "Bisogna sistemare anche l'orologio.\n"
	.string "Pensaci tu, tesoro!$"

PlayersHouse_1F_Text_ArentYouInterestedInRoom: @ 81F7B24
	.string "Mamma: Beh, {PLAYER}?\p"
	.string "Non sei interessato a vedere\n"
	.string "la tua stanza?$"

PlayersHouse_1F_Text_GoSetTheClock: @ 81F7B67
	.string "Mamma: {PLAYER}.\p"
	.string "Non dimenticarti di impostare l'orologio, tesoro.$"

PlayersHouse_1F_Text_OhComeQuickly: @ 81F7B96
	.string "Mamma: Oh! {PLAYER}, {PLAYER}!\n"
	.string "Presto! Presto!$"

PlayersHouse_1F_Text_MaybeDadWillBeOn: @ 81F7BBC
	.string "Mamma: Guarda! E' una notizia speciale!\n"
	.string "Dev'essere importante!$"

PlayersHouse_1F_Text_ItsOverWeMissedHim: @ 81F7BF1
	.string "Mamma: Oh… non ci voleva.. Sono\n"
	.string "in pensiero per tuo padre,\l"
	.string "dovrebbe tornare oggi dal suo,\l"
	.string "viaggio d'affari.$"

PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor: @ 81F7C35
	.string "Oh, quasi dimenticavo.\n"
	.string "Un'altra famiglia si è trasferita.\p"
	.string "qui a BELL.\p"
	.string "Vivono nella casa accanto.\n"
	.string "Vai a presentarti, tesoro.$"

PlayersHouse_1F_Text_SeeYouHoney: @ 81F7CC3
	.string "Mamma: Ci vediamo, tesoro!$"

PlayersHouse_1F_Text_DidYouMeetProfBirch: @ 81F7CD8
	.string "MOM: Ti sei presentato\n"
	.string "ai vicini?$"

PlayersHouse_1F_Text_YouShouldRestABit: @ 81F7D08
	.string "Mamma: Come stai, {PLAYER}?\n"
	.string "Sembri un pò stanco.\p"
	.string "Penso tu debba riposare.$"

PlayersHouse_1F_Text_TakeCareHoney: @ 81F7D5C
	.string "Mamma: stai attento, tesoro.$"

PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom: @ 81F7D73
	.string "MOM: Oh? Did DAD give you that BADGE?\p"
	.string "Then here's something from your MOM!$"

PlayersHouse_1F_Text_DontPushYourselfTooHard: @ 81F7DBE
	.string "Don't push yourself too hard, dear.\n"
	.string "You can always come home.\p"
	.string "Go for it, honey!$"

PlayersHouse_1F_Text_IsThatAPokenav: @ 81F7E0E
	.string "MOM: What is that, honey? A POKéNAV?\n"
	.string "Someone from DEVON gave it to you?\p"
	.string "Well, honey, how about registering\n"
	.string "your mom?\p"
	.string "… … …$"

PlayersHouse_1F_Text_RegisteredMom: @ 81F7E89
	.string "Registered MOM\n"
	.string "in the POKéNAV.$"

PlayersHouse_1F_Text_Vigoroth1: @ 81F7EA8
	.string "Fugiiiiih!$"

PlayersHouse_1F_Text_Vigoroth2: @ 81F7EB3
	.string "Huggoh, uggo uggo…$"

PlayersHouse_1F_Text_ReportFromPetalburgGym: @ 81F7EC6
.string "TV: Attenzione! Una banda di\n"
.string "malviventi sembra essersi\l"
.string "stabilita nella regione di Ancar!\l"
.string "Per qualsiasi tipo di problema,\l"
.string "non esitare a contattare la\l"
.string "Polizia! Questo è tutto da\l"
.string "PokéChannel!$"

PlayersHouse_1F_Text_TheresAMovieOnTV: @ 81F7F0F
	.string "La TV è spenta.$"

PlayersHouse_1F_Text_RunningShoesManual: @ 81F7F66
	.string "It's the instruction booklet for the\n"
	.string "RUNNING SHOES.\p"
	.string "“Press the B Button to run while\n"
	.string "wearing your RUNNING SHOES.\p"
	.string "“Lace up your RUNNING SHOES and hit\n"
	.string "the road running!”$"

PlayersHouse_1F_Text_TicketFromBrineyCameForYou: @ 81F800E
	.string "DAD: Hm?\p"
	.string "Hey, it's {PLAYER}!\p"
	.string "It's been a while since I saw you,\n"
	.string "but you look…stronger, somehow.\p"
	.string "That's the impression I get.\n"
	.string "But your old man hasn't given up yet!\p"
	.string "Oh, yes, I have something for you.\n"
	.string "This came to you from someone named\l"
	.string "MR. BRINEY.$"

PlayersHouse_1F_Text_PortsInSlateportLilycove: @ 81F80FE
	.string "DAD: Hm, a TICKET for a ferry?\p"
	.string "If I recall, there are ferry ports in\n"
	.string "SLATEPORT and LILYCOVE.$"

PlayersHouse_1F_Text_BetterGetBackToGym: @ 81F815B
	.string "I'd better get back to PETALBURG GYM.\p"
	.string "MOM, thanks for looking after the house\n"
	.string "while I'm away.$"

PlayersHouse_1F_Text_DadShouldStayLonger: @ 81F81B9
	.string "MOM: That DAD of yours…\p"
	.string "He comes home for the first time in a\n"
	.string "while, but all he talks about is POKéMON.\p"
	.string "He should relax and stay a little longer.$"

PlayersHouse_1F_Text_IsThatABreakingStory: @ 81F824B
	.string "MOM: Is that a breaking news story?$"

PlayersHouse_1F_Text_LatiEmergencyNewsFlash: @ 81F826F
	.string "We bring you this emergency\n"
	.string "news flash!\p"
	.string "In various HOENN locales, there have\n"
	.string "been reports of a BZZT…colored\l"
	.string "POKéMON in flight.\p"
	.string "The identity of this POKéMON is\n"
	.string "currently unknown.\p"
	.string "We now return you to the regular\n"
	.string "movie program.$"

PlayersHouse_1F_Text_WhatColorDidTheySay: @ 81F8351
	.string "MOM: {PLAYER}, did you catch that?\p"
	.string "What color did the announcer say\n"
	.string "that POKéMON was?$"

PlayersHouse_1F_Text_StillUnknownPokemon: @ 81F83A1
	.string "MOM: Well, isn't that something!\n"
	.string "There are still unknown POKéMON.$"
