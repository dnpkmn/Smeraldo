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
	compare VAR_UNUSED_0x4083, 1
	call_if_eq LittlerootTown_BrendansHouse_1F_EventScript_EeveeOWM
	end

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

	LittlerootTown_BrendansHouse_1F_EventScript_EeveeOWM::
	setobjectxyperm 1, 7, 5
    setobjectmovementtype 1, MOVEMENT_TYPE_FACE_RIGHT
    setobjectxyperm 5, 8, 5
    setobjectmovementtype 5, MOVEMENT_TYPE_FACE_LEFT
	return

@ Many of the below scripts have no gender check because they assume youre in the correct house
@ The below SS Ticket script uses Mays house state by accident(?), but theyre both set identically after the intro
LittlerootTown_BrendansHouse_1F_OnFrame: @ 81F77EA
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 1, LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 3, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
	map_script_2 VAR_UNUSED_0x4083, 1, LittlerootTown_BrendansHouse_1F_EventScript_Eevee
	.2byte 0

LittlerootTown_BrendansHouse_1F_EventScript_Eevee::
lock
compare VAR_UNUSED_0x4083, 1
goto_if_gt EventScript_Terminatoeeveeevent
playbgm MUS_ENCOUNTER_INTENSE, TRUE
playse SE_PIN
applymovement 5, movimento_guardobasso
applymovement 1, movimento_guardobasso
applymovement OBJ_EVENT_ID_PLAYER movimento_puntoesclamativo
waitmovement 0
msgbox primomex MSGBOX_DEFAULT
closemessage
msgbox secondomex MSGBOX_DEFAULT
closemessage
applymovement OBJ_EVENT_ID_PLAYER, movimento_unpassosopra
waitmovement 0
msgbox terzomex MSGBOX_DEFAULT
closemessage
applymovement 1, movimentowatchright
waitmovement 0
msgbox quartomex MSGBOX_DEFAULT
closemessage
applymovement 5, movimentowatchleft
waitmovement 0
msgbox quintomex MSGBOX_DEFAULT
closemessage
applymovement 5, movimento_guardobasso
waitmovement 0
msgbox sestomex MSGBOX_DEFAULT
closemessage
applymovement 1, movimentowatchright
waitmovement 0
msgbox settimomex MSGBOX_DEFAULT
applymovement 5, movimentowatchleft
waitmovement 0
msgbox ottavomex MSGBOX_DEFAULT
closemessage
applymovement 5, unpassosotto
applymovement 1, movimento_guardobasso
waitmovement 0
msgbox nonomex MSGBOX_DEFAULT
closemessage
playfanfare MUS_OBTAIN_ITEM
msgbox Text_ObtainedEevee, MSGBOX_DEFAULT
waitfanfare
closemessage
givemon SPECIES_EEVEE, 5, ITEM_SITRUS_BERRY
msgbox Text_soprannome MSGBOX_YESNO
compare VAR_RESULT 1
call_if_eq EventScript_NicknameEevee
closemessage
msgbox decimomex MSGBOX_DEFAULT
closemessage
applymovement 5, penultimomovimentodad
waitmovement 0
applymovement OBJ_EVENT_ID_PLAYER movimento_guardobasso
waitmovement 0
msgbox undicesimomex MSGBOX_DEFAULT
closemessage
applymovement 5, movimento_guardobasso
waitmovement 0
removeobject 5
applymovement 1, walk_rightdown
waitmovement 0
applymovement OBJ_EVENT_ID_PLAYER movimento_guardoalto
waitmovement 0
msgbox dodicesimomex MSGBOX_DEFAULT
closemessage
playfanfare MUS_OBTAIN_ITEM
msgbox Text_ObtainedScarpedacorsa, MSGBOX_DEFAULT
waitfanfare
closemessage
msgbox tredicesimomex MSGBOX_DEFAULT
closemessage
msgbox quattordicesimomex MSGBOX_DEFAULT
closemessage
savebgm MUS_DUMMY
fadedefaultbgm
setflag FLAG_HIDE_PLAYERS_HOUSE_DAD
setflag FLAG_SYS_POKEMON_GET
setflag FLAG_SYS_B_DASH
setvar VAR_UNUSED_0x4083, 2
setvar VAR_UNUSED_0x404E, 2
setvar VAR_UNUSED_0x408B, 1
setflag FLAG_UNUSED_0x020
setflag FLAG_HIDE_PLAYERS_HOUSE_DAD
releaseall
end

movimento_puntoesclamativo:
emote_exclamation_mark
step_end

movimento_guardoalto:
face_up
step_end

Text_soprannome:
.string "Papà: Vuoi dargli un soprannome?$"

EventScript_NicknameEevee::
setvar VAR_0x8004, 0
fadescreen 1
special ChangePokemonNickname
waitstate
return

Text_ObtainedEevee:
.string "{PLAYER} ha ricevuto Eevee!$"

movimento_guardobasso:
face_down
step_end

unpassosotto:
walk_down
step_end

movimento_unpassosopra:
walk_up
step_end

primomex:
.string "Mamma: Tesoro! Bentornato!$"

secondomex:
.string "Papà: Ciao {PLAYER}. Bentornato.$"

terzomex:
.string "Papà: Dov'eri andato di bello?$"

movimentowatchright:
face_right
step_end

movimentowatchleft:
face_left
step_end

quartomex:
.string "Mamma: E' andato a presentarsi dai\n"
.string "vicini di casa. Un'altra famiglia,\l"
.string "si è trasferita come noi, proprio\l"
.string "oggi, qui a Bell.$"

quintomex:
.string "Papà: Ah capisco.$"

sestomex:
.string "Papà: Bene, io devo andare via\n"
.string "adesso. Cercherò di tornare il\l"
.string "prima possibile.$"

settimomex:
.string "Mamma: Ma come? Sei appena\n"
.string "tornato..$"

ottavomex:
.string "Papà: Hai ragione, cara. Tuttavia,\n"
.string "devo incontrare una certa persona\l"
.string "per parlare di affari. A quel\l"
.string "punto, tornerò a casa, per passare\l"
.string "del tempo con la mia adorata\l"
.string "famiglia. Ahahaha!$"

nonomex:
.string "Papà: {PLAYER}. Oggi è il tuo\n"
.string "compleanno. Per questo, non potevo\l"
.string "non farti un regalo. Durante il\l"
.string "mio ultimo viaggio, ho trovato un\l"
.string "cucciolo di Eevee, probabilmente\l"
.string "abbandonato dal suo allenatore.\l"
.string "Non potevo lasciarlo lì, senza\l"
.string "fare nulla. Questo Pokémon ha\l"
.string "bisogno di un allenatore che lo\l"
.string "tratti bene. Questo è il mio\l"
.string "regalo per te, {PLAYER}.$"

decimomex:
.string "Papà: Non ho mai visto un Pokémon\n"
.string "così felice, prima d'ora. Eevee,\l"
.string "con te, è in ottime mani.$"

undicesimomex:
.string "Papà: A presto!$"

walk_rightdown:
walk_right
walk_down
step_end


EventScript_Terminatoeeveeevent::
releaseall
end

penultimomovimentodad:
walk_right
walk_down
walk_down
walk_left
face_up
step_end

dodicesimomex:
.string "Mamma: {PLAYER}, non è mai facile\n"
.string "per una madre, vedere il figlio\l"
.string "andare via di casa. Però, so\l"
.string "quanto hai desiderato avere un\l"
.string "Pokémon tutto tuo! Vorrei almeno\l"
.string "mi venissi a trovare ogni tanto.\p"
.string "Prima che tu vada via, voglio\n"
.string "nanche io farti un regalo. Sono\l"
.string "delle Scarpe da Corsa. Con queste\l"
.string "potrai andare ovunque, in men che\l"
.string "non si dica!$"

Text_ObtainedScarpedacorsa:
.string "{PLAYER} riceve le Scarpe da Corsa!$"

tredicesimomex:
.string "Mamma: E' il manuale per le Scarpe\n"
.string "da Corsa! Sembra esserci scritto..\l"
.string "Premere B per correre!$"

quattordicesimomex:
.string "Mamma: Buon viaggio, tesoro!$"

LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock:: @ 81F7814
	lockall
	msgbox PlayersHouse_1F_Text_GoSetTheClock, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	applymovement LOCALID_MOM, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	waitmovement 0
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, 255, 7, 1
	waitstate
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

PlayersHouse_1F_Text_IsntItNiceInHere:
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
	.string "Non dimenticarti di impostare\n"
	.string "l'orologio, tesoro.$"

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

PlayersHouse_1F_Text_0badgesmom:
	.string "Mamma: Mi raccomando, {PLAYER},\n"
	.string "abbi cura di te! Ricordati di\l"
	.string "venirmi a trovare ogni tanto!$"

PlayersHouse_1F_Text_1badgesmom:
.string "Mamma: Ma quella è una medaglia?\n"
.string "Bravo tesoro! Continua così!$"

PlayersHouse_1F_Text_2badgesmom:
.string "Mamma: Due medaglie? Vedo che ci\n"
.string "stai mettendo impegno, {PLAYER}. Io\l"
.string "sono sempre qui a supportarti, lo\l"
.string "sai!$"

PlayersHouse_1F_Text_3badgesmom:
.string "Mamma: Tre medaglie? Devo dire che\n"
.string "sei diventato un bravo allenatore,\l"
.string "{PLAYER}! Sono contenta per te!$"

PlayersHouse_1F_Text_4badgesmom:
.string "Mamma: Tesoro, ci stai davvero\n"
.string "mettendo il cuore in quello che\l"
.string "fai. Non potrei che essere fiera\l"
.string "di te!$"

PlayersHouse_1F_Text_5badgesmom:
.string "Mamma: Wow, più delle metà delle\n"
.string "medaglie della Regione, sei\l"
.string "proprio il figlio di tuo padre!$"

PlayersHouse_1F_Text_6badgesmom:

.string "Mamma: {PLAYER}, hai così tante\n"
.string "medaglie! Sei sempre più vicino al\l"
.string "tuo obiettivo. Sono davvero felice\l"
.string "per te!$"

PlayersHouse_1F_Text_7badgesmom:

.string "Mamma: {PLAYER}, sei diventato un\n"
.string "grande allenatore ormai. Ricordo\l"
.string "quando hai iniziato con Eevee ed\l"
.string "ora sei proprio ad un passo dal\l"
.string "tuo obiettivo. Tuo padre ed io\l"
.string "siamo estremamente fieri di avere\l"
.string "un figlio così talentuoso!$"

PlayersHouse_1F_Text_8badgesmom:

.string "Mamma: Tesoro, ce l'hai fatta! Hai\n"
.string "ottenuto tutte le medaglie!\l"
.string "Bisogna sicuramente festeggiare i\l"
.string "tuoi sforzi! Ho un regalo per te,\l"
.string "campione mio!$"

PlayersHouse_1F_Text_SeeYouHoney: @ 81F7CC3
.string "Mamma: Ci vediamo, tesoro!$"

PlayersHouse_1F_Text_DidYouMeetProfBirch: @ 81F7CD8
.string "Mamma: Tesoro, presentati ai\n"
.string "vicini di casa.$"

PlayersHouse_1F_Text_YouShouldRestABit: @ 81F7D08
	.string "Mamma: Come stai, {PLAYER}?\n"
	.string "Sembri un pò stanco.\p"
	.string "Penso tu debba riposare.$"

PlayersHouse_1F_Text_TakeCareHoney: @ 81F7D5C
	.string "Mamma: Stai attento, tesoro.$"

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

PlayerHouse_1F_Text_ObtainedMegaBracelet:
.string "{PLAYER} ha ricevuto Megacerchio!$"

PlayerHouse_1F_Text_idkMegaBracelet:
.string "Mamma: Non so a cosa serva ma\n"
.string "credo abbia qualche legame con\l"
.string "alcuni Pokémon. Spero che possa\l"
.string "esserti utile, tesoro.$"

Text_glnowchild:
.string "Mamma: Qualsiasi siano i tuoi\n"
.string "obiettivi, non dimenticarti mai\l"
.string "che sono sempre al tuo fianco!$"
