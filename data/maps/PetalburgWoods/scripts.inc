.set LOCALID_GRUNT, 3
.set LOCALID_DEVON_EMPLOYEE, 4

PetalburgWoods_MapScripts:: @ 822DFD6
	.byte 0

PetalburgWoods_EventScript_DevonResearcherLeft:: @ 822DFD7
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherLeft
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachPlayer
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitLeft
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherRight:: @ 822E079
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherRight
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitRight
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherIntro:: @ 822E124
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
	waitmovement 0
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_DevonResearcherPostBattle:: @ 822E138
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaRunAway
	waitmovement 0
	removeobject LOCALID_GRUNT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL
	compare VAR_RESULT, FALSE
	goto_if_eq PetalburgWoods_EventScript_BagFull
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_BagFull:: @ 822E17D
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_DevonResearcherFinish:: @ 822E18B
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
	waitmovement 0
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_RemoveDevonResearcher:: @ 822E1A7
	removeobject LOCALID_DEVON_EMPLOYEE
	setvar VAR_PETALBURG_WOODS_STATE, 1
	releaseall
	end

PetalburgWoods_Movement_DevonResearcherLookAround: @ 822E1B1
	face_up
	delay_16
	delay_4
	face_right
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	face_down
	delay_16
	face_right
	delay_16
	delay_8
	face_up
	delay_16
	step_end

PetalburgWoods_Movement_DevonResearcherExitLeft: @ 822E1C2
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft: @ 822E1CB
	delay_16
	face_player
	walk_down
	walk_down
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerRight: @ 822E1D0
	delay_16
	face_player
	walk_down
	walk_down
	walk_down
	walk_in_place_fastest_right
	step_end

PetalburgWoods_Movement_DevonResearcherExitRight: @ 822E1D7
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_WatchResearcherLeave: @ 822E1E0
	delay_16
	delay_16
	walk_in_place_fastest_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft: @ 822E1E4
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_in_place_fastest_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight: @ 822E1EA
	walk_fast_down
	walk_fast_right
	walk_in_place_fastest_up
	step_end

PetalburgWoods_Movement_DevonResearcherStartExit: @ 822E1EE
	walk_in_place_fastest_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_up
	step_end

PetalburgWoods_Movement_AquaApproachResearcherLeft: @ 822E1F6
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaBackOff: @ 822E1F9
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

PetalburgWoods_Movement_AquaRunAway: @ 822E1FD
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachResearcherRight: @ 822E205
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaEntrance: @ 822E209
	walk_down
	walk_down
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachPlayer: @ 822E20E
	walk_down
	step_end

PetalburgWoods_EventScript_Elliot_1:: @ 822E219
trainerbattle_single TRAINER_ELLIOT_1, Elliot1_Text_Intro, Elliot1_Text_Defeat
msgbox Elliot1_Text_postbattle, MSGBOX_AUTOCLOSE
end

PetalburgWoods_EventScript_Claude:: @ 822E219
trainerbattle_single TRAINER_CLAUDE, Claude_Text_Intro, Claude_Text_Defeat
msgbox Claude_Text_postbattle, MSGBOX_AUTOCLOSE
end

PetalburgWoods_EventScript_James_1:: @ 822E219
trainerbattle_single TRAINER_JAMES_1, James1_Text_Intro, James1_Text_Defeat
msgbox James1_Text_postbattle, MSGBOX_AUTOCLOSE
end

PetalburgWoods_EventScript_James_2:: @ 822E219
trainerbattle_single TRAINER_JAMES_2, James2_Text_Intro, James2_Text_Defeat
msgbox James1_Text_postbattle, MSGBOX_AUTOCLOSE
end

Elliot1_Text_Intro:
.string "E' tutto il giorno che pesco!\n"
.string "Speriamo ne valga la pena!$"

Elliot1_Text_Defeat:
.string "Uff, ne varrà veramente la pena?$"

Elliot1_Text_postbattle:
.string "Perché non peschiamo insieme? E'\n"
.string "una buona zona per pescare.$"

Claude_Text_Intro:
.string "Pescare è una dote innata!$"

Claude_Text_Defeat:
.string "Wow! Anche lottare lo è!$"

Claude_Text_postbattle:
.string "Dici che è pericoloso, pescare nel\n"
.string "Bosco Driade?$"

James1_Text_Intro:
.string "Questo Bosco è pieno di insidie!$"

James1_Text_Defeat: 
.string "Eheheh, tu sei un'insidia!$"

James1_Text_postbattle:
.string "Bisogna stare attenti ai Pokémon\n"
.string "selvatici del Bosco.$"

James2_Text_Intro:
.string "Sai dirmi dove siamo?$"

James2_Text_Defeat:
.string "Riconosco le tue capacità!$"

James2_Text_postbattle:
.string "Accidenti.. forse mi sarò perso?$"

PetalburgWoods_EventScript_Henry:: @ 822E222
trainerbattle_single TRAINER_HENRY, Henry_Text_Intro, HenryText_Defeat
msgbox Henry_Text_postbattle, MSGBOX_AUTOCLOSE
end

PetalburgWoods_EventScript_Kent:: @ 822E222
trainerbattle_single TRAINER_KENT, Kent_Text_Intro, KentText_Defeat
msgbox Kent_Text_postbattle, MSGBOX_AUTOCLOSE
end

Kent_Text_Intro:
.string "Mi sento forte! Ho catturato tante\n"
.string "specie di Pokémon!$"

KentText_Defeat:
.string "Ugh..devo migliorare la qualità\n"
.string "più che la quantità..$"

Kent_Text_postbattle:
.string "Allenare più specie è sicuramente\n"
.string "più difficile, ma credo ripaghi\l"
.string "alla fine.$"

Henry_Text_Intro:
.string "Pesco con il mio Amo Vecchio!\n"
.string "Vediamone la qualità!$"

HenryText_Defeat:
.string "Accidenti, devo utilizzare un Amo\nmigliore..$"

Henry_Text_postbattle:
.string "Ci sono Ami migliori del mio!$"

PetalburgWoods_EventScript_ExplainMiracleSeed:: @ 822E251
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_Sign1:: @ 822E25B
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Sign2:: @ 822E264
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Lyle:: @ 822E26D
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_EventScript_Jonah:: @ 822E284
trainerbattle_single TRAINER_JONAH, PetalburgWoods_Text_JonahIntro, PetalburgWoods_Text_JonahDefeat
msgbox PetalburgWoods_Text_JonahPostBattle, MSGBOX_AUTOCLOSE
end

PetalburgWoods_Text_JonahIntro:
.string "Umh, sei abboccato alla mia esca!\n"
.string "Lottiamo!$"

PetalburgWoods_Text_JonahDefeat:
.string "Umh, e così ho beccato un pesce\n"
.string "grosso?$"

PetalburgWoods_Text_JonahPostBattle:
.string "Umh, a volte non abbocca nulla!$"

PetalburgWoods_Text_NotAOneToBeFound: @ 822E332
	.string "Hmmm…\n"
	.string "Not a one to be found…$"

PetalburgWoods_Text_HaveYouSeenShroomish: @ 822E34F
	.string "Hello, have you seen any POKéMON\n"
	.string "called SHROOMISH around here?\p"
	.string "I really love that POKéMON.$"

PetalburgWoods_Text_IWasGoingToAmbushYou: @ 822E3AA
	.string "I was going to ambush you, but you\n"
	.string "had to dawdle in PETALBURG WOODS\l"
	.string "forever, didn't you?\p"
	.string "I got sick of waiting, so here I am!$"

PetalburgWoods_Text_HandOverThosePapers: @ 822E428
	.string "You! DEVON RESEARCHER!\p"
	.string "Hand over those papers!$"

PetalburgWoods_Text_YouHaveToHelpMe: @ 822E457
	.string "Aiyeeeh!\p"
	.string "You're a POKéMON TRAINER, aren't you?\n"
	.string "You've got to help me, please!$"

PetalburgWoods_Text_NoOneCrossesTeamAqua: @ 822E4A5
	.string "Hunh? What do you think you're doing?\n"
	.string "What, you're going to protect him?\p"
	.string "No one who crosses TEAM AQUA\n"
	.string "gets any mercy, not even a kid!\p"
	.string "Come on and battle me!$"

PetalburgWoods_Text_YoureKiddingMe: @ 822E542
	.string "You're kidding me! You're tough!$"

PetalburgWoods_Text_YouveGotSomeNerve: @ 822E563
	.string "Grrr… You've got some nerve\n"
	.string "meddling with TEAM AQUA!\l"
	.string "Come on and battle me again!\p"
	.string "I wish I could say that, but I'm out of\n"
	.string "POKéMON…\p"
	.string "And, hey, we of TEAM AQUA are also\n"
	.string "after something in RUSTBORO.\p"
	.string "I'll let you go today!$"

PetalburgWoods_Text_ThatWasAwfullyClose: @ 822E63D
	.string "Whew…\n"
	.string "That was awfully close!\p"
	.string "Thanks to you, he didn't rob me of\n"
	.string "these important papers.\p"
	.string "I know, I'll give you a GREAT BALL as\n"
	.string "my thanks!$"

PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro: @ 822E6C7
	.string "Didn't that TEAM AQUA thug say\n"
	.string "they were after something in\l"
	.string "RUSTBORO, too?$"

PetalburgWoods_Text_ICantBeWastingTime: @ 822E712
	.string "Uh-oh! It's a crisis!\n"
	.string "I can't be wasting time!$"

PetalburgWoods_Text_YoureLoadedWithItems: @ 822E741
	.string "You're loaded with items.\n"
	.string "I can't give you this GREAT BALL.$"

PetalburgWoods_Text_GoBugPokemonTeam: @ 822E77D
	.string "I caught a whole bunch of POKéMON!\p"
	.string "Go, go, go!\n"
	.string "My BUG POKéMON team!$"

PetalburgWoods_Text_ICouldntWin: @ 822E7C1
	.string "I have all these POKéMON,\n"
	.string "but I couldn't win…$"

PetalburgWoods_Text_ImOutOfPokeBalls: @ 822E7EF
	.string "I caught a bunch of POKéMON.\n"
	.string "Now I'm out of POKé BALLS.$"

PetalburgWoods_Text_InstantlyPopularWithBugPokemon: @ 822E827
	.string "If you take BUG POKéMON to school,\n"
	.string "you get to be instantly popular!$"

PetalburgWoods_Text_CantBePopularIfILose: @ 822E86B
	.string "I can't be popular if I lose.$"

PetalburgWoods_Text_PeopleRespectYou: @ 822E889
	.string "If you have a big BUG POKéMON,\n"
	.string "people respect you for it.$"

PetalburgWoods_Text_IWantRematch1: @ 822E8C3
	.string "I want a rematch when my BUG\n"
	.string "POKéMON grow up!\p"
	.string "I'm registering you in my POKéNAV!$"

PetalburgWoods_Text_IWantRematch2: @ 822E914
	.string "I want a rematch when my BUG \n"
	.string "POKéMON grow up!\p"
	.string "I'm registering you in my POKéNAV!$"

PetalburgWoods_Text_MyPokemonHaveGrown: @ 822E966
	.string "My BUG POKéMON have grown.\n"
	.string "I'll be popular again.$"

PetalburgWoods_Text_CantBePopularIfLose: @ 822E998
	.string "I can't be popular if I lose.$"

PetalburgWoods_Text_IveBeenTrainingHard: @ 822E9B6
	.string "You get to be popular if you have\n"
	.string "strong POKéMON, right?\l"
	.string "So, I've been training hard.$"

PetalburgWoods_Text_StayOutOfTallGrass: @ 822EA0C
	.string "Yo, there!\n"
	.string "Your POKéMON doing okay?\p"
	.string "If your POKéMON are weak and you want\n"
	.string "to avoid battles, you should stay out\l"
	.string "of tall grass.$"

PetalburgWoods_Text_HiddenItemsExplanation: @ 822EA8B
	.string "Sometimes, there are things on the\n"
	.string "ground even if you can't see them.\p"
	.string "That's why I always check where I'm\n"
	.string "walking.$"

PetalburgWoods_Text_TryUsingThisItem: @ 822EAFE
	.string "Oh, neat!\n"
	.string "That's the BADGE from RUSTBORO GYM!\p"
	.string "You must be a TRAINER.\n"
	.string "You should try using this item.$"

PetalburgWoods_Text_MiracleSeedExplanation: @ 822EB63
	.string "It's a MIRACLE SEED.\n"
	.string "If a POKéMON holds that item, its\l"
	.string "GRASS-type moves become stronger.\p"
	.string "Besides MIRACLE SEED, I think there are\n"
	.string "other convenient items for POKéMON\l"
	.string "to hold.$"

PetalburgWoods_Text_TrainerTipsExperience: @ 822EC10
	.string "TRAINER TIPS\p"
	.string "Any POKéMON that appears even once\n"
	.string "in a battle is awarded EXP Points.\p"
	.string "To raise a weak POKéMON, put it at the\n"
	.string "left of the team list.\p"
	.string "As soon as a battle starts, switch it\n"
	.string "out. It will earn EXP Points without\l"
	.string "being exposed to any harm.$"

PetalburgWoods_Text_TrainerTipsPP: @ 822ED07
	.string "TRAINER TIPS\p"
	.string "In addition to Hit Points (HP), POKéMON\n"
	.string "have Power Points (PP) that are used to\l"
	.string "make moves during battle.\p"
	.string "If a POKéMON runs out of PP, it must be\n"
	.string "taken to a POKéMON CENTER.$"

EventScript_SxBoscodriade::
lockall
compare VAR_UNUSED_0x40B8, 0
goto_if_gt EventScript_salvadanaiodone
playbgm MUS_ENCOUNTER_AQUA, TRUE
applymovement OBJ_EVENT_ID_PLAYER m1_boscodriadesx
waitmovement 0
closemessage
msgbox chat1boscodriade, MSGBOX_DEFAULT
closemessage
msgbox chat2boscodriade, MSGBOX_DEFAULT
closemessage
applymovement 4, m2_boscodriade
applymovement 14, m2_boscodriade
waitmovement 0
msgbox chat3boscodriade, MSGBOX_DEFAULT
closemessage
msgbox chat4boscodriade, MSGBOX_DEFAULT
closemessage
msgbox chat5boscodriade, MSGBOX_DEFAULT
closemessage
applymovement OBJ_EVENT_ID_PLAYER, m3_boscodriade
applymovement 4, mfaceright_boscodriade
applymovement 14, m5_boscodriade
waitmovement 0
trainerbattle_no_intro TRAINER_GRUNT_RUSTURF_TUNNEL, Boscodriade_Text_defeat
msgbox chat7boscodriade, MSGBOX_DEFAULT
closemessage
fadescreen 1
removeobject 4
fadescreen 0
applymovement 14, m4_boscodriade
applymovement OBJ_EVENT_ID_PLAYER mfaceright_boscodriade
waitmovement 0
msgbox grazietienisoldi, MSGBOX_DEFAULT
playfanfare MUS_OBTAIN_B_POINTS
addmoney 3000, 0x00
waitfanfare
closemessage
msgbox grazietienisoldi2, MSGBOX_DEFAULT
closemessage
applymovement 14, m6_boscodriade
applymovement OBJ_EVENT_ID_PLAYER, m7_boscodriade
waitmovement 0
removeobject 14
setflag FLAG_HIDE_PETALBURG_WOODS_DEVON_EMPLOYEE
savebgm MUS_DUMMY
special HealPlayerParty
setvar VAR_UNUSED_0x40B8, 1
fadedefaultbgm
releaseall
end

EventScript_DxBoscodriade::
lockall
compare VAR_UNUSED_0x40B8, 0
goto_if_gt EventScript_salvadanaiodone
playbgm MUS_ENCOUNTER_AQUA, TRUE
applymovement OBJ_EVENT_ID_PLAYER m1_boscodriadedx
waitmovement 0
closemessage
msgbox chat1boscodriade, MSGBOX_DEFAULT
closemessage
msgbox chat2boscodriade, MSGBOX_DEFAULT
closemessage
applymovement 4, m2_boscodriade
applymovement 14, m2_boscodriade
waitmovement 0
msgbox chat3boscodriade, MSGBOX_DEFAULT
closemessage
msgbox chat4boscodriade, MSGBOX_DEFAULT
closemessage
msgbox chat5boscodriade, MSGBOX_DEFAULT
closemessage
applymovement OBJ_EVENT_ID_PLAYER, m3_boscodriade
applymovement 4, mfaceright_boscodriade
applymovement 14, m5_boscodriade
waitmovement 0
trainerbattle_no_intro TRAINER_GRUNT_RUSTURF_TUNNEL, Boscodriade_Text_defeat
msgbox chat7boscodriade, MSGBOX_DEFAULT
closemessage
fadescreen 1
removeobject 4
fadescreen 0
applymovement 14, m4_boscodriade
applymovement OBJ_EVENT_ID_PLAYER mfaceright_boscodriade
waitmovement 0
msgbox grazietienisoldi, MSGBOX_DEFAULT
playfanfare MUS_OBTAIN_B_POINTS
addmoney 3000, 0x00
waitfanfare
closemessage
msgbox grazietienisoldi2, MSGBOX_DEFAULT
closemessage
applymovement 14, m6_boscodriade
applymovement OBJ_EVENT_ID_PLAYER, m7_boscodriade
waitmovement 0
removeobject 14
setflag FLAG_HIDE_PETALBURG_WOODS_DEVON_EMPLOYEE
savebgm MUS_DUMMY
special HealPlayerParty
setvar VAR_UNUSED_0x40B8, 1
fadedefaultbgm
releaseall
end

mfaceright_boscodriade:
face_right
step_end

grazietienisoldi:
.string "Richard: Grazie! Grazie! Grazie!\n"
.string "Non volevo dare il salvadanaio a\l"
.string "quei farabutti del Team Sakkara!\l"
.string "Sembrano molto pericolosi, bisogna\l"
.string "fare attenzione, probabilmente è\l"
.string "di loro che parlava la TV. Io sono\l"
.string "ricco però per principio non do\l"
.string "i miei soldi a dei criminali.\l"
.string "Per avermi salvato, voglio però\l"
.string "sdebitarmi e non avendo nulla con\l"
.string "me, ti darò del denaro! Non fare\l"
.string "complimenti su!$"

grazietienisoldi2:
.string "Richard: Ho altri Salvadanai, però\n"
.string "a casa mia, a Wolf. Se passi a\l"
.string "trovarmi te ne regalerò uno!\l"
.string "Grazie ancora!$"

Boscodriade_Text_defeat:
.string "Recluta: Ho perso?! Che incubo!$"

chat1boscodriade:
.string "???: E così, volete i miei soldi\n"
.string "eh? Non vedi che non ho un Pokémon\l"
.string "con me? Non posso combattere!$"

chat2boscodriade:
.string "Team Sakkara: Non mi interessa.\n"
.string "Tanto meglio per me, così potrò\l"
.string "strapparti via quel Salvadanaio\l"
.string "senza alcun problema.$"

chat3boscodriade:
.string "Team Sakkara: Chi sei? Ah.. sei\n"
.string "solo un ragazzino. Credo tu sia in\l"
.string "tempo a cambiare strada, pivello.$"

chat4boscodriade:
.string "???: Hey ragazzino, mi chiamo\n"
.string "Richard, per favore, se hai un\l"
.string "Pokémon con te, ti chiedo di\l"
.string "aiutarmi! Se necessario, sono\l"
.string "disposto a pagarti! I soldi non mi\l"
.string "mancano!$"

chat5boscodriade:
.string "Team Sakkara: Vorresti mettere in\n"
.string "pericolo un ragazzino? Ahah, fai\l"
.string "pure, fatti avanti e prenderò\l"
.string "anche i tuoi Pokémon! Il Team\l"
.string "Sakkara è il Team per eccellenza,\l"
.string "non avete a che fare con quegli\l"
.string "smidollati degli altri Team.\l"
.string "Ti ridurrò a brandelli, cimice!$"

chat7boscodriade:
.string "Recluta: Sono solo una Recluta, ma\n"
.string "non pensavo di poter perdere qui!\l"
.string "E va bene, tieniti pure i tuoi\l"
.string "soldi, tanto il Team Sakkara è\l"
.string "destinato a farne un mare!$"

m1_boscodriadedx:
walk_left
walk_up
emote_question_mark
step_end

m1_boscodriadesx:
walk_up
emote_question_mark
step_end

m2_boscodriade:
face_down
emote_exclamation_mark
step_end

m3_boscodriade:
walk_up
walk_left
walk_up
face_left
step_end

m4_boscodriade:
walk_left
step_end

m5_boscodriade:
face_left
step_end

m6_boscodriade:
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

m7_boscodriade:
face_up
step_end

EventScript_salvadanaiodone::
releaseall
end
