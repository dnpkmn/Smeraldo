.set LOCALID_WALLY, 2
.set LOCALID_BOY, 3
.set LOCALID_WALLYS_DAD, 5
.set LOCALID_GYM_BOY, 8
.set LOCALID_SCOTT, 9

PetalburgCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_OnFrame
	.byte 0

PetalburgCity_OnTransition: @ 81DC2D7
	setflag FLAG_VISITED_PETALBURG_CITY
	compare VAR_UNUSED_0x4091, 1
	call_if_eq PetalburgCity_EventScript_Movecharacters
	compare VAR_PETALBURG_CITY_STATE, 2
	call_if_eq PetalburgCity_EventScript_DisableMapNameAndMusic
	compare VAR_PETALBURG_CITY_STATE, 4
	call_if_eq PetalburgCity_EventScript_DisableMapNameAndMusic
	compare VAR_PETALBURG_GYM_STATE, 8
	call_if_eq PetalburgCity_EventScript_SetGymDoorsUnlocked
	end

EventScript_TeamSakkarafightsopra::
lockall
compare VAR_UNUSED_0x409B, 0
goto_if_gt EventScript_finish
playbgm MUS_RG_ENCOUNTER_ROCKET, TRUE
applymovement OBJ_EVENT_ID_PLAYER, Move_1up
waitmovement 0
msgbox Text_maniacvssakkara1, MSGBOX_DEFAULT
closemessage
msgbox Text_maniacvssakkara2, MSGBOX_DEFAULT
closemessage
playse SE_PIN
applymovement OBJ_EVENT_ID_PLAYER, wondermove
waitmovement 0
msgbox Text_maniacvssakkara3, MSGBOX_DEFAULT
closemessage
applymovement 6, jumpmovekec
waitmovement 0
msgbox Text_maniacvssakkara4, MSGBOX_DEFAULT
closemessage
applymovement 7, finalmovepoochyenawon
waitmovement 0
playmoncry SPECIES_KECLEON, 0
msgbox Text_maniaclostkeccry, MSGBOX_DEFAULT
waitmoncry
closemessage
applymovement 6, invisible
waitmovement 0
msgbox Text_maniacvssakkara5, MSGBOX_DEFAULT
closemessage
applymovement 7, guardaasinistra
msgbox Text_maniacvssakkara6 MSGBOX_DEFAULT
closemessage
msgbox Text_maniacvssakkara7, MSGBOX_DEFAULT
closemessage
msgbox Text_maniacvssakkara8, MSGBOX_DEFAULT
closemessage
applymovement 5, puntointesclteamsak
applymovement 7, puntointesclteamsak
applymovement 9, puntointesclteamsak
waitmovement 0
msgbox chiseiteamsakkara MSGBOX_DEFAULT
closemessage
msgbox dialogocont MSGBOX_YESNO
compare VAR_RESULT, NO
call_if_eq EventScriptusaidnovsteamsakkara
msgbox dialogocont2 MSGBOX_DEFAULT
closemessage
msgbox dialogocont3 MSGBOX_DEFAULT
closemessage
msgbox dialogocont4 MSGBOX_DEFAULT
closemessage
applymovement 7, goupnowpoochyena
applymovement 9, almostfinalmoveteamsakkaraguy
waitmovement 0
msgbox dialogocont5 MSGBOX_DEFAULT
closemessage
msgbox dialogocont6 MSGBOX_DEFAULT
closemessage
trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_impossibileno
msgbox dialogocont6 MSGBOX_DEFAULT
closemessage
applymovement 7, invisible
waitmovement 0
msgbox grandioso MSGBOX_DEFAULT
closemessage
msgbox finalthendisappearsakkara MSGBOX_DEFAULT
closemessage
fadescreen 1
removeobject 9
removeobject 7
applymovement 6, faceupkecleonfinalevent
waitmovement 0
fadescreen 0
applymovement 5, lastmovemaniacmascar
applymovement OBJ_EVENT_ID_PLAYER fl
waitmovement 0
msgbox thanksmate MSGBOX_DEFAULT
playfanfare MUS_OBTAIN_ITEM
giveitem ITEM_RARE_CANDY, 1
waitfanfare
closemessage
savebgm MUS_DUMMY
fadedefaultbgm
special HealPlayerParty
setflag FLAG_ITEM_PETALBURG_CITY_ETHER
setvar VAR_UNUSED_0x409B, 1
setvar VAR_UNUSED_0x4091, 2
releaseall
end

EventScript_TeamSakkarafightsotto::
lockall
compare VAR_UNUSED_0x409B, 0
goto_if_gt EventScript_finish
playbgm MUS_RG_ENCOUNTER_ROCKET, TRUE
applymovement OBJ_EVENT_ID_PLAYER, Move_1down
waitmovement 0
msgbox Text_maniacvssakkara1, MSGBOX_DEFAULT
closemessage
msgbox Text_maniacvssakkara2, MSGBOX_DEFAULT
closemessage
playse SE_PIN
applymovement OBJ_EVENT_ID_PLAYER, wondermove
waitmovement 0
msgbox Text_maniacvssakkara3, MSGBOX_DEFAULT
closemessage
applymovement 6, jumpmovekec
waitmovement 0
msgbox Text_maniacvssakkara4, MSGBOX_DEFAULT
closemessage
applymovement 7, finalmovepoochyenawon
waitmovement 0
playmoncry SPECIES_KECLEON, 0
msgbox Text_maniaclostkeccry, MSGBOX_DEFAULT
waitmoncry
closemessage
applymovement 6, invisible
waitmovement 0
msgbox Text_maniacvssakkara5, MSGBOX_DEFAULT
closemessage
applymovement 7, guardaasinistra
msgbox Text_maniacvssakkara6 MSGBOX_DEFAULT
closemessage
msgbox Text_maniacvssakkara7, MSGBOX_DEFAULT
closemessage
msgbox Text_maniacvssakkara8, MSGBOX_DEFAULT
closemessage
applymovement 5, puntointesclteamsak
applymovement 7, puntointesclteamsak
applymovement 9, puntointesclteamsak
waitmovement 0
msgbox chiseiteamsakkara MSGBOX_DEFAULT
closemessage
msgbox dialogocont MSGBOX_YESNO
compare VAR_RESULT, NO
call_if_eq EventScriptusaidnovsteamsakkara
msgbox dialogocont2 MSGBOX_DEFAULT
closemessage
msgbox dialogocont3 MSGBOX_DEFAULT
closemessage
msgbox dialogocont4 MSGBOX_DEFAULT
closemessage
applymovement 7, goupnowpoochyena
applymovement 9, almostfinalmoveteamsakkaraguy
waitmovement 0
msgbox dialogocont5 MSGBOX_DEFAULT
closemessage
msgbox dialogocont6 MSGBOX_DEFAULT
closemessage
trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_impossibileno
msgbox dialogocont6 MSGBOX_DEFAULT
closemessage
applymovement 7, invisible
waitmovement 0
msgbox grandioso MSGBOX_DEFAULT
closemessage
msgbox finalthendisappearsakkara MSGBOX_DEFAULT
closemessage
fadescreen 1
removeobject 9
removeobject 7
applymovement 6, faceupkecleonfinalevent
waitmovement 0
fadescreen 0
applymovement 5, lastmovemaniacmascar
applymovement OBJ_EVENT_ID_PLAYER fl
waitmovement 0
msgbox thanksmate MSGBOX_DEFAULT
playfanfare MUS_OBTAIN_ITEM
giveitem ITEM_RARE_CANDY, 1
waitfanfare
closemessage
savebgm MUS_DUMMY
fadedefaultbgm
special HealPlayerParty
setflag FLAG_ITEM_PETALBURG_CITY_ETHER
setvar VAR_UNUSED_0x409B, 1
setvar VAR_UNUSED_0x4091, 2
releaseall
end

fl:
face_left
step_end

Text_Obtainedrarecandy:
.string "{PLAYER} ottiene 1 Caramella Rara!$"

thanksmate:
.string "Tizio a sinistra: Non so veramente\n"
.string "come ringraziarti. Kecleon è il\l"
.string "mio unico amico, grazie al cielo\l"
.string "mi hai salvato! Non saprei come\l"
.string "sdebitarmi ma ho un oggetto raro\l"
.string "e voglio regalartelo! Grazie\l"
.string "ancora!!$"

lastmovemaniacmascar:
walk_up
walk_up
walk_right
walk_right
step_end

faceupkecleonfinalevent:
set_visible
face_up
step_end

finalthendisappearsakkara:
.string "Tizio a destra: Dannazione..come\n"
.string "ho potuto perdere contro una\l"
.string "formica come te! In ogni caso, il\l"
.string "Team Sakkara, prima o poi, si\l"
.string "prenderà tutti i Pokémon! E' una\l"
.string "promessa!$"

grandioso:
.string "Tizio a sinistra: Wow! Hai vinto!\n"
.string "Sei stato grandioso!$"

PetalburgWoods_Text_impossibileno:
.string "Non posso crederci! Battuto da un\n"
.string "ragazzino!$"

goupnowpoochyena:
walk_up
step_end

almostfinalmoveteamsakkaraguy:
walk_left
face_up
step_end

EventScriptusaidnovsteamsakkara::
msgbox noncicredoamico MSGBOX_DEFAULT
closemessage
return

noncicredoamico:
.string "Tizio a sinistra: Andiamo, amico,\n"
.string "non ci credo! Sicuramente se sei\l"
.string "qui è perché vuoi salvarmi!$"

dialogocont2:
.string "Tizio a destra: Vuoi salvare\n"
.string "questo perdente? Ahahaha, forse\l"
.string "non conosci le regole del Team\l"
.string "Sakkara. Chi perde contro di noi,\l"
.string "paga un prezzo, ovvero il suo\l"
.string "Pokémon diventa nostra proprietà!$"

dialogocont3:
.string "Tizio a sinistra: E' vero, loro\n"
.string "giocano sporco. Non hanno nessuna\l"
.string "pietà per gli allenatori e si\l"
.string "divertono a strappargli via i loro\l"
.string "Pokémon. Non sottovalutarli! Non\l"
.string "sei obbligato a recuperare il mio\l"
.string "Kecleon!$"

dialogocont4:
.string "Tizio a destra: Sembra che non ti\n"
.string "importi, beh, allora vediamo cosa\l"
.string "sai fare, nanerottolo!$"

dialogocont5:
.string "Tizio a destra: Forza Poochyena,\n"
.string "prendiamoci anche i suoi Pokémon!$"

dialogocont6:
.string "Poochyena: Poochyena!$"

chiseiteamsakkara:
.string "Tizio a destra: Che cos'hai da\n"
.string "guardare moscerino?$"

dialogocont:
.string "Tizio a sinistra: Hai l'aria di\n"
.string "essere un allenatore, non sarai\l"
.string "mica venuto a salvarmi?$"

passogiumascar:
walk_down
step_end

puntointesclteamsak:
face_up
emote_question_mark
emote_exclamation_mark
step_end

jumpmovekec:
jump_right
step_end

invisible:
set_invisible
step_end

guardaasinistra:
face_left
step_end

wondermove:
emote_question_mark
step_end

Move_1down:
walk_left
walk_up
walk_left
walk_left
walk_left
walk_left
walk_left
face_down
emote_exclamation_mark
step_end

Move_1up:
walk_left
walk_left
walk_left
walk_left
walk_left
walk_left
face_down
emote_exclamation_mark
step_end

Text_maniacvssakkara1:
.string "Tizio a sinistra: Forza Kecleon!\n"
.string "Facciamogli vedere cosa sappiamo\l"
.string "fare!$"

Text_maniacvssakkara2:

.string "Tizio a destra: Ahahah, forse ti\n"
.string "sei dimenticato la posta in gioco.\l"
.string "Non appena perderai, il tuo caro\l"
.string "Pokémon diventerà mio!$"

Text_maniacvssakkara3:
.string "Tizio a sinistra: Lo stesso vale\n"
.string "per il tuo Pokémon. Io e il mio\l"
.string "Kecleon non perderemo mai, forza\l"
.string "amico diamogli il colpo decisivo!$"

Text_maniacvssakkara4:
.string "Tizio a destra: Niente male.\n"
.string "Tuttavia, non puoi vincere contro\l"
.string "il Team Sakkara. Forza Poochyena,\l"
.string "diamogli il colpo di grazia!$"

Text_maniaclostkeccry:
.string "Kecleon: Kecl...e..on..$"

Text_maniacvssakkara5:
.string "Tizio a sinistra: Nooo, Kecleon!$"

Text_maniacvssakkara6:
.string "Tizio a destra: Ahahahaha! Dì pure\n"
.string "addio al tuo Kecleon! O forse\l"
.string "dovrei dire..al MIO Kecleon!$"

Text_maniacvssakkara7:
.string "Tizio a sinistra: Farò quello che\n"
.string "vuoi, ma ti prego, non portarmelo\l"
.string "via! E' l'unico amico che ho!$"

Text_maniacvssakkara8:
.string "Tizio a destra: Ahahahah, non mi\n"
.string "importa affatto! Chi perde contro\l"
.string "il Team Sakkara, paga un prezzo\l"
.string "molto alto, la prossima volta,\l"
.string "allenati di più! Ahahaha!$"

finalmovepoochyenawon:
jump_in_place_left
jump_in_place_left
jump_in_place_left
step_end

EventScript_endingg::
releaseall
end

	PetalburgCity_EventScript_Movecharacters::
	setobjectxyperm 5, 29, 20
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm 6, 30, 20
	setobjectmovementtype 6, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm 7, 32, 20
	setobjectmovementtype 7, MOVEMENT_TYPE_FACE_LEFT
	setobjectxyperm 9, 33, 20
	setobjectmovementtype 9, MOVEMENT_TYPE_FACE_LEFT
	return

PetalburgCity_EventScript_DisableMapNameAndMusic:: @ 81DC30F
	setflag FLAG_HIDE_MAP_NAME_POPUP
	savebgm MUS_FOLLOW_ME
	return

PetalburgCity_EventScript_SetGymDoorsUnlocked:: @ 81DC316
	setvar VAR_PETALBURG_GYM_STATE, 7
	return

PetalburgCity_OnFrame: @ 81DC31C
	map_script_2 VAR_PETALBURG_CITY_STATE, 2, PetalburgCity_EventScript_WallyTutorial
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_EventScript_WalkToWallyHouse
	.2byte 0

PetalburgCity_EventScript_WallyTutorial:: @ 81DC32E
	lockall
	special SavePlayerParty
	special PutZigzagoonInPlayerParty
	applymovement LOCALID_WALLY, PetalburgCity_Movement_WallyTutorialWally
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_WallyTutorialPlayer
	waitmovement 0
	msgbox Route102_Text_WatchMeCatchPokemon, MSGBOX_DEFAULT
	special StartWallyTutorialBattle
	waitstate
	msgbox Route102_Text_WallyIDidIt, MSGBOX_DEFAULT
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFastestLeft, MAP_PETALBURG_CITY
	waitmovement LOCALID_WALLY, MAP_PETALBURG_CITY
	msgbox Route102_Text_LetsGoBack, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_PETALBURG_CITY_STATE, 3
	fadedefaultbgm
	clearflag FLAG_DONT_TRANSITION_MUSIC
	special LoadPlayerParty
	setvar VAR_PETALBURG_GYM_STATE, 1
	warp MAP_PETALBURG_CITY_GYM, 255, 4, 108
	waitstate
	releaseall
	end

PetalburgCity_EventScript_WalkToWallyHouse:: @ 81DC390
	lockall
	setflag FLAG_HIDE_MAP_NAME_POPUP
	applymovement LOCALID_WALLYS_DAD, PetalburgCity_Movement_WalkToWallyHouseWallysDad
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_WalkToWallyHousePlayer
	waitmovement 0
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 5
	opendoor VAR_0x8004, VAR_0x8005
	waitdooranim
	applymovement LOCALID_WALLYS_DAD, PetalburgCity_Movement_WalkInsideHouseWallysDad
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_WalkInsideHousePlayer
	waitmovement 0
	setflag FLAG_HIDE_PETALBURG_CITY_WALLYS_DAD
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_PETALBURG_CITY
	closedoor VAR_0x8004, VAR_0x8005
	waitdooranim
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	fadedefaultbgm
	clearflag FLAG_DONT_TRANSITION_MUSIC
	warp MAP_PETALBURG_CITY_WALLYS_HOUSE, 255, 2, 4
	waitstate
	releaseall
	end

PetalburgCity_EventScript_WallysMom:: @ 81DC3FD
	msgbox PetalburgCity_Text_WhereIsWally, MSGBOX_NPC
	end

PetalburgCity_Movement_WalkToWallyHousePlayer: @ 81DC406
	delay_8
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PetalburgCity_Movement_WalkInsideHousePlayer: @ 81DC418
	walk_up
	walk_up
	step_end

PetalburgCity_Movement_WalkToWallyHouseWallysDad: @ 81DC41B
	delay_8
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PetalburgCity_Movement_WalkInsideHouseWallysDad: @ 81DC42D
	walk_up
	set_invisible
	step_end

PetalburgCity_Movement_WallyTutorialPlayer: @ 81DC430
	delay_8
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_in_place_fastest_right
	step_end

PetalburgCity_Movement_WallyTutorialWally: @ 81DC451
	delay_8
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	delay_16
	walk_in_place_fastest_up
	delay_16
	delay_16
	walk_in_place_fastest_right
	step_end

PetalburgCity_EventScript_GymSign:: @ 81DC476
	msgbox PetalburgCity_Text_GymSign, MSGBOX_SIGN
	end

PetalburgCity_EventScript_CitySign:: @ 81DC47F
	msgbox PetalburgCity_Text_CitySign, MSGBOX_SIGN
	end

PetalburgCity_EventScript_Gentleman:: @ 81DC488
	msgbox PetalburgCity_Text_FullPartyExplanation, MSGBOX_NPC
	end

PetalburgCity_EventScript_WallyHouseSign:: @ 81DC491
	msgbox PetalburgCity_Text_WallyHouseSign, MSGBOX_SIGN
	end

PetalburgCity_EventScript_ShowGymToPlayer0:: @ 81DC49A
	lockall
	setvar VAR_0x8008, 0
	goto PetalburgCity_EventScript_ShowGymToPlayer
	end

PetalburgCity_EventScript_ShowGymToPlayer1:: @ 81DC4A6
	lockall
	setvar VAR_0x8008, 1
	goto PetalburgCity_EventScript_ShowGymToPlayer
	end

PetalburgCity_EventScript_ShowGymToPlayer2:: @ 81DC4B2
	lockall
	setvar VAR_0x8008, 2
	goto PetalburgCity_EventScript_ShowGymToPlayer
	end

PetalburgCity_EventScript_ShowGymToPlayer3:: @ 81DC4BE
	lockall
	setvar VAR_0x8008, 3
	goto PetalburgCity_EventScript_ShowGymToPlayer
	end

PetalburgCity_EventScript_ShowGymToPlayer:: @ 81DC4CA
	applymovement LOCALID_GYM_BOY, Common_Movement_FacePlayer
	waitmovement 0
	playbgm MUS_FOLLOW_ME, FALSE
	playse SE_PIN
	applymovement LOCALID_GYM_BOY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_GYM_BOY, Common_Movement_Delay48
	waitmovement 0
	compare VAR_0x8008, 0
	call_if_eq PetalburgCity_EventScript_BoyApproachPlayer0
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_EventScript_BoyApproachPlayer1
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_EventScript_BoyApproachPlayer2
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_EventScript_BoyApproachPlayer3
	msgbox PetalburgCity_Text_AreYouRookieTrainer, MSGBOX_DEFAULT
	closemessage
	compare VAR_0x8008, 0
	call_if_eq PetalburgCity_EventScript_LeadPlayerToGym0
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_EventScript_LeadPlayerToGym1
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_EventScript_LeadPlayerToGym2
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_EventScript_LeadPlayerToGym3
	msgbox PetalburgCity_Text_ThisIsPetalburgGym, MSGBOX_DEFAULT
	applymovement LOCALID_GYM_BOY, Common_Movement_WalkInPlaceFastestRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox PetalburgCity_Text_ThisIsGymSign, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyWalkAway
	waitmovement 0
	fadedefaultbgm
	releaseall
	end

PetalburgCity_Text_ThisIsGymSign:
.string "ok$"

PetalburgCity_EventScript_BoyApproachPlayer0:: @ 81DC57F
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyApproachPlayer0
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

PetalburgCity_EventScript_BoyApproachPlayer1:: @ 81DC594
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyApproachPlayer1
	waitmovement 0
	return

PetalburgCity_EventScript_BoyApproachPlayer2:: @ 81DC59F
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyApproachPlayer2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	return

PetalburgCity_EventScript_BoyApproachPlayer3:: @ 81DC5B4
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyApproachPlayer3
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	return

PetalburgCity_EventScript_LeadPlayerToGym0:: @ 81DC5C9
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyWalkToGym0
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_PlayerWalkToGym0
	waitmovement 0
	return

PetalburgCity_EventScript_LeadPlayerToGym1:: @ 81DC5DB
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyWalkToGym1
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_PlayerWalkToGym1
	waitmovement 0
	return

PetalburgCity_EventScript_LeadPlayerToGym2:: @ 81DC5ED
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyWalkToGym2
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_PlayerWalkToGym2
	waitmovement 0
	return

PetalburgCity_EventScript_LeadPlayerToGym3:: @ 81DC5FF
	applymovement LOCALID_GYM_BOY, PetalburgCity_Movement_BoyWalkToGym3
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_PlayerWalkToGym3
	waitmovement 0
	return

@ Unused
PetalburgCity_Movement_Delay48:: @ 81DC611
	delay_16
	delay_16
	delay_16
	step_end

PetalburgCity_Movement_BoyApproachPlayer0: @ 81DC615
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

PetalburgCity_Movement_BoyApproachPlayer1: @ 81DC61A
	walk_right
	walk_right
	step_end

PetalburgCity_Movement_BoyApproachPlayer2: @ 81DC61D
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_down
	step_end

PetalburgCity_Movement_BoyApproachPlayer3: @ 81DC622
	walk_down
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_down
	step_end

PetalburgCity_Movement_BoyWalkToGym0: @ 81DC628
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_right
	walk_in_place_fastest_up
	step_end

PetalburgCity_Movement_BoyWalkToGym1: @ 81DC633
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_in_place_fastest_up
	step_end

PetalburgCity_Movement_BoyWalkToGym2: @ 81DC641
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_right
	walk_in_place_fastest_up
	step_end

PetalburgCity_Movement_BoyWalkToGym3: @ 81DC64C
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_in_place_fastest_up
	step_end

PetalburgCity_Movement_BoyWalkAway: @ 81DC658
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_PlayerWalkToGym0: @ 81DC665
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

PetalburgCity_Movement_PlayerWalkToGym1: @ 81DC66F
	delay_16
	delay_16
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

PetalburgCity_Movement_PlayerWalkToGym2: @ 81DC67C
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

PetalburgCity_Movement_PlayerWalkToGym3: @ 81DC686
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

PetalburgCity_EventScript_Scott0:: @ 81DC691
	lockall
	addobject LOCALID_SCOTT
	setvar VAR_0x8008, 0
	setobjectxy LOCALID_SCOTT, 13, 10
	goto PetalburgCity_EventScript_Scott
	end

PetalburgCity_EventScript_Scott1:: @ 81DC6A7
	lockall
	addobject LOCALID_SCOTT
	setvar VAR_0x8008, 1
	setobjectxy LOCALID_SCOTT, 13, 11
	goto PetalburgCity_EventScript_Scott
	end

PetalburgCity_EventScript_Scott2:: @ 81DC6BD
	lockall
	addobject LOCALID_SCOTT
	setvar VAR_0x8008, 2
	setobjectxy LOCALID_SCOTT, 13, 12
	goto PetalburgCity_EventScript_Scott
	end

PetalburgCity_EventScript_Scott3:: @ 81DC6D3
	lockall
	addobject LOCALID_SCOTT
	setvar VAR_0x8008, 3
	setobjectxy LOCALID_SCOTT, 13, 13
	goto PetalburgCity_EventScript_Scott
	end

PetalburgCity_EventScript_Scott:: @ 81DC6E9
	applymovement LOCALID_SCOTT, PetalburgCity_Movement_ScottStartWalkLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_SCOTT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SCOTT, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_SCOTT, PetalburgCity_Movement_ScottApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	setvar VAR_SCOTT_STATE, 1
	msgbox PetalburgCity_Text_AreYouATrainer, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	delay 30
	msgbox PetalburgCity_Text_WellMaybeNot, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	delay 30
	msgbox PetalburgCity_Text_ImLookingForTalentedTrainers, MSGBOX_DEFAULT
	closemessage
	compare VAR_0x8008, 0
	call_if_eq PetalburgCity_EventScript_ScottExit0
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_EventScript_ScottExit1
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_EventScript_ScottExit2
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_EventScript_ScottExit3
	setvar VAR_SCOTT_PETALBURG_ENCOUNTER, 1
	removeobject LOCALID_SCOTT
	releaseall
	end

PetalburgCity_EventScript_ScottExit0:: @ 81DC78E
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_PlayerWatchScottExit0
	applymovement LOCALID_SCOTT, PetalburgCity_Movement_ScottExit0
	waitmovement 0
	return

PetalburgCity_EventScript_ScottExit1:: @ 81DC7A0
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_PlayerWatchScottExit1
	applymovement LOCALID_SCOTT, PetalburgCity_Movement_ScottExit1
	waitmovement 0
	return

PetalburgCity_EventScript_ScottExit2:: @ 81DC7B2
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_PlayerWatchScottExit2
	applymovement LOCALID_SCOTT, PetalburgCity_Movement_ScottExit2
	waitmovement 0
	return

PetalburgCity_EventScript_ScottExit3:: @ 81DC7C4
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_PlayerWatchScottExit3
	applymovement LOCALID_SCOTT, PetalburgCity_Movement_ScottExit3
	waitmovement 0
	return

PetalburgCity_Movement_ScottStartWalkLeft: @ 81DC7D6
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_ScottApproachPlayer: @ 81DC7DB
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_ScottExit0: @ 81DC7E0
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_PlayerWatchScottExit0: @ 81DC7EE
	delay_16
	walk_in_place_fastest_down
	delay_16
	delay_16
	delay_8
	walk_in_place_fastest_left
	step_end

PetalburgCity_Movement_ScottExit1: @ 81DC7F5
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_PlayerWatchScottExit1: @ 81DC802
	delay_16
	walk_in_place_fastest_down
	delay_16
	delay_8
	walk_in_place_fastest_left
	step_end

PetalburgCity_Movement_ScottExit2: @ 81DC808
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_PlayerWatchScottExit2: @ 81DC815
	delay_16
	walk_in_place_fastest_down
	delay_16
	delay_8
	walk_in_place_fastest_left
	step_end

PetalburgCity_Movement_ScottExit3: @ 81DC81B
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_EventScript_Beauty::
    lock
	faceplayer
	random 3
	switch VAR_RESULT
	case 0, Script_RandomOptionfirst
	case 1, Script_RandomOptionsecond
	case 2, Script_RandomOptionthird
	end

Script_RandomOptionfirst::
	msgbox Text_RandomOptionone, MSGBOX_DEFAULT
	release
	end

Script_RandomOptionsecond::
	msgbox Text_RandomOptiontwo, MSGBOX_DEFAULT
	release
	end

Script_RandomOptionthird::
	msgbox Text_RandomOptionthree, MSGBOX_DEFAULT
	release
	end

Text_RandomOptionone:
.string "Secondo te, qual è il Pokémon più\n"
.string "bello?\l"
.string "Per me è MILOTIC.\l"
.string "E' veramente incantevole!$"

Text_RandomOptiontwo:
.string "Non prendo mai le lotte Pokémon\n"
.string "sul serio. Mi limito a guardare\l"
.string "quanto sono belli i miei Pokémon!$"

Text_RandomOptionthree:
.string "Un allenatore della tua età, prima\n"
.string "l'ho visto uscire dalla palestra\l"
.string "con aria soddisfatta!$"

	PetalburgCity_EventScript_Boy::
    lock
	faceplayer
	random 3
	switch VAR_RESULT
	case 0, Script_1tx
	case 1, Script_2tx
	case 2, Script_3tx
	end

Script_1tx::
	msgbox Text_unor, MSGBOX_DEFAULT
	release
	end

Script_2tx::
	msgbox Text_duer, MSGBOX_DEFAULT
	release
	end

Script_3tx::
	msgbox Text_trer, MSGBOX_DEFAULT
	release
	end
	
Text_unor:
.string "Dannazione! Ho perso ancora contro\n"
.string "il Capopalestra! E' veramente un\l"
.string "osso duro..$"

Text_duer:

.string "Penso che dovrei utilizzare una\n"
.string "tipologia adatta per la sfida alla\l"
.string "palestra!$"

Text_trer:
.string "La prossima città non è molto\n"
.string "lontana, però.. ho sentito dire\l"
.string "che c'è un bosco da attraversare\l"
.string "prima.$"

PetalburgCity_Text_GymSign: @ 81DCAAA
	.string "Palestra Pokémon di Mascar.\n"
	.string "Capopalestra: KALI$"

PetalburgCity_Script_LabSign::
	msgbox PetalburgCity_Text_LABSign MSGBOX_SIGN
	end

PetalburgCity_Text_LABSign:
    .string "Laboratorio Pokémon\n"
	.string "Professore: Sherman$"

PetalburgCity_Text_CitySign:
	.string "Mascar\n"
	.string "{RIGHT_ARROW} Percorso 3\l"
	.string "{LEFT_ARROW} Percorso 4$"

PetalburgCity_Text_WallyHouseSign: @ 81DCB23
	.string "Casa di MR Nick$"

PetalburgCity_EventScript_Maniac::
lock
faceplayer
msgbox text_savedme MSGBOX_NPC
release
end

text_savedme:
.string "Ti sarò per sempre grato, per\n"
.string "avermi aiutato contro quel tizio!\l"
.string "Non so cosa sarebbe successo al\l"
.string "mio Kecleon se non fossi arrivato\l"
.string "tu a salvarmi, amico!$"

PetalburgCity_Text_WhereIsWally: @ 81DC837
	.string "Oggi è un pò nuvoloso, chissà se\n"
	.string "pioverà.$"

PetalburgCity_Text_AreYouRookieTrainer:

	.string "Mi dispiace, giovane sfidante.\n"
	.string "Kali si sta riposando, dopo\l"
	.string "l'ultima lotta.$"


EventScript_Kek::
    lock
	faceplayer
	playmoncry SPECIES_KECLEON, 0
	msgbox Text_CryKecleon, MSGBOX_DEFAULT
	waitmoncry
    closemessage
	release
	end

Text_CryKecleon:
.string "Kecleon: Kec! Kec!$"

PetalburgCity_Movement_PlayerWatchScottExit3: @ 81DC828
	delay_16
	walk_in_place_fastest_up
	delay_16
	delay_8
	walk_in_place_fastest_left
	step_end

PetalburgCity_EventScript_GymBoy:: @ 81DC82E
	msgbox PetalburgCity_Text_AreYouRookieTrainer, MSGBOX_NPC
	end

PetalburgCity_Text_ThisIsPetalburgGym: @ 81DC91B
	.string "See? This is PETALBURG CITY's GYM.$"


PetalburgCity_Text_WaterReflection: @ 81DC985
	.string "My face is reflected in the water.\p"
	.string "It's a shining grin full of hope…\p"
	.string "Or it could be a look of somber silence\n"
	.string "struggling with fear…\p"
	.string "What do you see reflected in your face?$"

PetalburgCity_Text_FullPartyExplanation: @ 81DCA30
	.string "Let's say you have six POKéMON.\n"
	.string "If you catch another one…\p"
	.string "It is automatically sent to a STORAGE\n"
	.string "BOX over a PC connection.$"

PetalburgCity_Text_AreYouATrainer: @ 81DCB31
	.string "Excuse me!\p"
	.string "Let me guess, from the way you're\n"
	.string "dressed, are you a POKéMON TRAINER?$"

PetalburgCity_Text_WellMaybeNot: @ 81DCB82
	.string "… … … … … …\p"
	.string "Well, maybe not.\n"
	.string "Your clothes aren't all that dirty.\p"
	.string "You're either a rookie TRAINER,\n"
	.string "or maybe you're just an ordinary kid.$"

PetalburgCity_Text_ImLookingForTalentedTrainers: @ 81DCC09
	.string "I'm roaming the land in search of\n"
	.string "talented TRAINERS.\p"
	.string "I'm sorry to have taken your time.$"

EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED, EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_SEEDOT
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox Text_WillingToTradeIt, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, 255
	goto_if_eq EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	compare VAR_RESULT, VAR_0x8009
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname 0, VAR_0x8009
	msgbox Text_ItsSubtlyDifferentThankYou, MSGBOX_DEFAULT
	setflag FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED
	release
	end

EventScript_TradeCompleted::
lock
faceplayer
msgbox text_takecareofducklett MSGBOX_NPC
release
end

text_takecareofducklett:
.string "Spearow è proprio il Pokémon che\n"
.string "cercavo! Tratta con cura Ducklett.$"

Text_WillingToTradeIt: @ 8203CBE
	.string "Vorrei proporti uno scambio.\n"
	.string "Posso darti il mio Ducklett in\l"
	.string "cambio di uno Spearow.$"

Text_ItsSubtlyDifferentThankYou: @ 8203D87
	.string "Che bello questo Spearow! E'\n"
	.string "proprio il Pokémon che cercavo!$"

	EventScript_DeclineTrade:: @ 8203C93
	msgbox Text_NotDesperateOrAnything, MSGBOX_DEFAULT
	release
	end

	Text_WontAcceptAnyLessThanRealMon: @ 8203DDE
    .string "Non mi interessano altri Pokémon.\n"
	.string "Se non hai uno Spearow, terrò il\l"
	.string "mio Ducklett.$"

	Text_NotDesperateOrAnything: @ 8203E12
	.string "Quindi non ti interessa? Che\n"
	.string "peccato. Spero di trovare uno\l"
	.string "Spearow prima o poi..$"

	Text_ReallyWantedToGetBagon: @ 8203E7F
	.string "Forse potrò trovare uno Spearow\n"
	.string "nell'erba alta, però sarebbe più\l"
	.string "comodo ottenerlo tramite uno\l"
	.string "scambio.$"
