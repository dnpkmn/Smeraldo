@ NOTE: Route 104's sail to Dewford script references local IDs from Dewford's map. 
@  These are labeled in DewfordTown/scripts.inc
.set LOCALID_RIVAL, 34

Route104_MapScripts:: @ 81ECC32
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route104_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_OnTransition
	.byte 0

Route104_OnFrame: @ 81ECC3D
	map_script_2 VAR_BOARD_BRINEY_BOAT_STATE, 1, Route104_EventScript_StartSailToDewford
	.2byte 0

Route104_EventScript_StartSailToDewford:: @ 81ECC47
	lockall
	goto Route104_EventScript_SailToDewford
	end

Route104_OnTransition: @ 81ECC4E
	call Common_EventScript_SetupRivalGfxId
	call Route104_EventScript_TrySetRivalPos
	call Route104_EventScript_ShowOrHideWhiteHerbFlorist
	end

Route104_EventScript_ShowOrHideWhiteHerbFlorist:: @ 81ECC5E
	goto_if_unset FLAG_MET_PRETTY_PETAL_SHOP_OWNER, Route104_EventScript_HideWhiteHerbFlorist
	goto_if_unset FLAG_BADGE03_GET, Route104_EventScript_HideWhiteHerbFlorist
	clearflag FLAG_HIDE_ROUTE_104_WHITE_HERB_FLORIST
	return

Route104_EventScript_HideWhiteHerbFlorist:: @ 81ECC74
	setflag FLAG_HIDE_ROUTE_104_WHITE_HERB_FLORIST
	return

Route104_EventScript_TrySetRivalPos:: @ 81ECC78
	compare VAR_BOARD_BRINEY_BOAT_STATE, 1
	goto_if_ge Route104_EventScript_DontSetRivalPos
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, Route104_EventScript_DontSetRivalPos
	goto_if_unset FLAG_REGISTER_RIVAL_POKENAV, Route104_EventScript_DontSetRivalPos
	return

Route104_EventScript_DontSetRivalPos:: @ 81ECC9D
	return

Route104_EventScript_Rival:: @ 81ECC9E
	lockall
	setvar VAR_0x8008, 1
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	goto Route104_EventScript_RivalEncounter

Route104_EventScript_RivalTrigger:: @ 81ECCB3
	lockall
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setvar VAR_RUSTBORO_CITY_STATE, 8
	setvar VAR_ROUTE104_STATE, 2
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	delay 10
	addobject LOCALID_RIVAL
	clearflag FLAG_HIDE_ROUTE_104_RIVAL
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerBackUp
	waitmovement 0
	applymovement LOCALID_RIVAL, Route104_Movement_RivalExitBrineysCottage
	waitmovement 0
	delay 20
	setvar VAR_0x8008, 0
	call RustboroCity_EventScript_PlayRivalMusic
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	goto Route104_EventScript_RivalEncounter

@ Unused, shares script with Rustboro encounter instead
Route104_EventScript_PlayRivalMusic:: @ 81ECD11
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route104_EventScript_PlayMayMusic
	compare VAR_RESULT, FEMALE
	goto_if_eq Route104_EventScript_PlayBrendanMusic
	return

Route104_EventScript_PlayMayMusic:: @ 81ECD29
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

Route104_EventScript_PlayBrendanMusic:: @ 81ECD2E
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

Route104_EventScript_RivalEncounter:: @ 81ECD33
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route104_EventScript_MayEncounter
	compare VAR_RESULT, FEMALE
	goto_if_eq Route104_EventScript_BrendanEncounter
	end

Route104_EventScript_MayEncounter:: @ 81ECD4B
	goto_if_set FLAG_DEFEATED_RIVAL_ROUTE_104, Route104_EventScript_MayDefeated
	goto_if_set FLAG_REGISTER_RIVAL_POKENAV, Route104_EventScript_MayAskToBattle
	setflag FLAG_REGISTER_RIVAL_POKENAV
	msgbox Route104_Text_MayWeShouldRegister, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox Route104_Text_RegisteredMay, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerFaceRival
	applymovement LOCALID_RIVAL, Route104_Movement_RivalWalkSlowLeft
	msgbox Route104_Text_MayHowsYourPokedex, MSGBOX_DEFAULT
	closemessage
	waitmovement 0
	applymovement LOCALID_RIVAL, Route104_Movement_RivalApproachPlayer
	waitmovement 0
	copyobjectxytoperm LOCALID_RIVAL
	msgbox Route104_Text_MayMinesDecentLetsBattle, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route104_EventScript_BattleMay
	msgbox Route104_Text_MayHaventRaisedPokemon, MSGBOX_DEFAULT
	call Route104_EventScript_RestoreMusic
	releaseall
	end

Route104_Movement_RivalWalkSlowLeft: @ 81ECDC8
	walk_slow_left
	step_end

Route104_Movement_RivalApproachPlayer: @ 81ECDCA
	walk_down
	face_right
	step_end

Route104_Movement_PlayerFaceRival: @ 81ECDCD
	delay_4
	walk_in_place_fastest_left
	step_end

Route104_EventScript_MayAskToBattle:: @ 81ECDD0
	msgbox Route104_Text_MayLetsBattle, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route104_EventScript_BattleMay
	msgbox Route104_Text_MayHaventRaisedPokemon, MSGBOX_DEFAULT
	releaseall
	end

Route104_EventScript_BattleMay:: @ 81ECDED
	msgbox Route104_Text_MayIntro, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route104_EventScript_BattleMayTreecko
	case 1, Route104_EventScript_BattleMayTorchic
	case 2, Route104_EventScript_BattleMayMudkip
	end

Route104_EventScript_MayDefeated:: @ 81ECE1C
	msgbox Route104_Text_MayPostBattle, MSGBOX_DEFAULT
	compare VAR_0x8008, 0
	call_if_eq Route104_EventScript_RestoreMusic
	releaseall
	end

Route104_EventScript_RestoreMusic:: @ 81ECE31
	savebgm MUS_DUMMY
	fadedefaultbgm
	return

Route104_EventScript_BattleMayTreecko:: @ 81ECE36
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TREECKO, Route104_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
	goto Route104_EventScript_MayDefeated
	end

Route104_EventScript_BattleMayTorchic:: @ 81ECE49
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TORCHIC, Route104_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
	goto Route104_EventScript_MayDefeated
	end

Route104_EventScript_BattleMayMudkip:: @ 81ECE5C
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_MUDKIP, Route104_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
	goto Route104_EventScript_MayDefeated
	end

Route104_EventScript_BrendanEncounter:: @ 81ECE6F
	goto_if_set FLAG_DEFEATED_RIVAL_ROUTE_104, Route104_EventScript_BrendanDefeated
	goto_if_set FLAG_REGISTER_RIVAL_POKENAV, Route104_EventScript_BrendanAskToBattle
	setflag FLAG_REGISTER_RIVAL_POKENAV
	msgbox Route104_Text_BrendanWeShouldRegister, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox Route104_Text_RegisteredBrendan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerFaceRival
	applymovement LOCALID_RIVAL, Route104_Movement_RivalWalkSlowLeft
	msgbox Route104_Text_BrendanHowsYourPokedex, MSGBOX_DEFAULT
	closemessage
	waitmovement 0
	applymovement LOCALID_RIVAL, Route104_Movement_RivalApproachPlayer
	waitmovement 0
	copyobjectxytoperm LOCALID_RIVAL
	msgbox Route104_Text_BrendanDoingGreatLetsBattle, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route104_EventScript_BattleBrendan
	msgbox Route104_Text_BrendanNoConfidence, MSGBOX_DEFAULT
	call Route104_EventScript_RestoreMusic
	releaseall
	end

Route104_EventScript_BrendanAskToBattle:: @ 81ECEEC
	msgbox Route104_Text_BrendanLetsBattle, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route104_EventScript_BattleBrendan
	msgbox Route104_Text_BrendanNoConfidence, MSGBOX_DEFAULT
	releaseall
	end

Route104_EventScript_BattleBrendan:: @ 81ECF09
	msgbox Route104_Text_BrendanIntro, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route104_EventScript_BattleBrendanTreecko
	case 1, Route104_EventScript_BattleBrendanTorchic
	case 2, Route104_EventScript_BattleBrendanMudkip
	end

Route104_EventScript_BrendanDefeated:: @ 81ECF38
	msgbox Route104_Text_BrendanPostBattle, MSGBOX_DEFAULT
	compare VAR_0x8008, 0
	call_if_eq Route104_EventScript_RestoreMusic
	releaseall
	end

Route104_EventScript_BattleBrendanTreecko:: @ 81ECF4D
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TREECKO, Route104_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
	goto Route104_EventScript_BrendanDefeated
	end

Route104_EventScript_BattleBrendanTorchic:: @ 81ECF60
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TORCHIC, Route104_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
	goto Route104_EventScript_BrendanDefeated
	end

Route104_EventScript_BattleBrendanMudkip:: @ 81ECF73
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_MUDKIP, Route104_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
	goto Route104_EventScript_BrendanDefeated
	end

Route104_Movement_PlayerBackUp: @ 81ECF86
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

Route104_Movement_RivalExitBrineysCottage: @ 81ECF8A
	walk_down
	step_end

Percorso5_EventScript_Kai:: @ 81ECF8C
trainerbattle_single TRAINER_KAI, Percorso5_Text_KaiIntro, Percorso5_Text_KaiDefeat
msgbox Percorso5_Text_KaiPostBattle, MSGBOX_AUTOCLOSE
end

Route104_EventScript_ReceivedBerry:: @ 81ECFC3
	msgbox Route104_Text_TrainersOftenMakeMonHoldBerries, MSGBOX_DEFAULT
	release
	end

Percorso5_EventScript_Ashley:: @ 81ECFCD
trainerbattle_single TRAINER_ASHLEY, Percorso5_Text_AshleyIntro, Percorso5_Text_AshleyDefeat
msgbox Percorso5_Text_AshleyPostBattle, MSGBOX_AUTOCLOSE
end

Route104_EventScript_ReceivedWhiteHerb:: @ 81ECFFC
	msgbox Route104_Text_FlowerShopSellingSaplings, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_Girl1:: @ 81ED006
	msgbox Route104_Text_BrineyLivesInSeasideCottage, MSGBOX_NPC
	end

Percorso4_EventScript_Deandre:: @ 81ED00F
	trainerbattle_single TRAINER_DEANDRE, Percorso4_Text_DeandreIntro, Percorso4_Text_DeandreDefeat
	msgbox Percorso4_Text_DeandrePostBattle, MSGBOX_AUTOCLOSE
	end

Percorso4_Text_DeandreIntro:
.string "Il mio Pokémon è forte! Stai a\n"
.string "vedere!$"

Percorso4_Text_DeandreDefeat:
.string "Anche la tua squadra, non scherza\n"
.string "affatto eh!$"

Percorso4_Text_DeandrePostBattle:
.string "La sconfitta mi va bene. E' dalle\n"
.string "sconfitte che si diventa vincenti!$"

Route104_EventScript_BrineysCottageSign:: @ 81ED018
	msgbox Route104_Text_MrBrineysCottage, MSGBOX_SIGN
	end

Route104_EventScript_RouteSignPetalburg:: @ 81ED021
	msgbox Route104_Text_RouteSignPetalburg, MSGBOX_SIGN
	end

Route104_EventScript_RouteSignRustboro:: @ 81ED02A
	msgbox Route104_Text_RouteSignRustboro, MSGBOX_SIGN
	end

Route104_EventScript_FlowerShopSign:: @ 81ED033
	msgbox Route104_Text_PrettyPetalFlowShop, MSGBOX_SIGN
	end

Route104_EventScript_TrainerTipsDoubleBattles:: @ 81ED03C
	msgbox Route104_Text_TrainerTipsDoubleBattles, MSGBOX_SIGN
	end

Route104_EventScript_Boy1:: @ 81ED045
    trainerbattle_single TRAINER_TAKAO, Percorso4Takaochat_intro, Percorso4_Text_TakaoDefeat
	msgbox Percorso4Takaochat_postbattle, MSGBOX_AUTOCLOSE
	end

Route104_EventScript_Woman:: @ 81ED04E
	trainerbattle_single TRAINER_ZANDER, Percorso4Zanderchat_intro, Percorso4_Text_ZanderDefeat
	msgbox Percorso4Zanderchat_postbattle, MSGBOX_AUTOCLOSE
	end

Percorso4_Text_TakaoDefeat:
.string "Accidenti, pensavo l'allenamento\n"
.string "fosse sufficiente!$"

Percorso4_Text_ZanderDefeat:
.string "Tu sì che hai stoffa da vendere!$"

Percorso4Takaochat_postbattle:
.string "A quanto pare, dovrò allenarmi\n"
.string "molto di più!$"

Percorso4Zanderchat_postbattle:
.string "Vedo che hai allenato bene i tuoi\n"
.string "Pokémon!$"

Percorso4Zanderchat_intro:
.string "Heh, l'allenamento è finito! Ora\n"
.string "vedrò i suoi frutti!$"

Percorso4Takaochat_intro:
.string "L'allenamento è fondamentale per\n"
.string "un allenatore e i suoi Pokémon!$"

Percorso5_EventScript_Flint:: @ 81ED057
trainerbattle_single TRAINER_FLINT, Percorso5_Text_FlintIntro, Percorso5_Text_FlintDefeat
msgbox Percorso5_Text_FlintPostBattle, MSGBOX_AUTOCLOSE
end

Route104_EventScript_ReceivedBulletSeed:: @ 81ED086
	msgbox Route104_Text_TMsAreOneTimeUse, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_Girl2:: @ 81ED090
	msgbox Route104_Text_ImNotATrainer, MSGBOX_NPC
	end

Route104_EventScript_SailToDewford:: @ 81ED099
	applymovement LOCALID_BRINEY_R104, Route104_Movement_BrineyBoardBoat
	waitmovement 0
	removeobject LOCALID_BRINEY_R104
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerBoardBoat
	waitmovement 0
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_ROUTE104
	call Common_EventScript_PlayBrineysBoatMusic
	goto_if_set FLAG_ENABLE_NORMAN_MATCH_CALL, Route104_EventScript_SailToDewfordNoCall
	goto_if_unset FLAG_ENABLE_NORMAN_MATCH_CALL, Route104_EventScript_SailToDewfordDadCalls
	end

Route104_EventScript_SailToDewfordNoCall:: @ 81ED0D9
	applymovement LOCALID_BOAT_R104, Route104_Movement_SailToDewford
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_SailToDewford
	waitmovement 0
	goto Route104_EventScript_ArriveInDewford

Route104_EventScript_SailToDewfordDadCalls:: @ 81ED0EF
	applymovement LOCALID_BOAT_R104, Route104_Movement_SailToDewfordBeforeDadCalls
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_SailToDewfordBeforeDadCalls
	waitmovement 0
	pokenavcall Route104_Text_DadPokenavCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox Route104_Text_RegisteredDadInPokenav, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_NORMAN_MATCH_CALL
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_SailToDewfordAfterDadCalls
	applymovement LOCALID_BOAT_R104, Route104_Movement_SailToDewfordAfterDadCalls, MAP_ROUTE104
	waitmovement LOCALID_BOAT_R104, MAP_ROUTE104
	waitmovement 0
	goto Route104_EventScript_ArriveInDewford

Route104_EventScript_ArriveInDewford:: @ 81ED139
	delay 50
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerExitBoat
	waitmovement 0
	call Common_EventScript_StopBrineysBoatMusic
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_DEWFORD_TOWN
	applymovement OBJ_EVENT_ID_PLAYER, Route104_Movement_PlayerMoveForBriney
	waitmovement 0
	clearflag FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN
	applymovement LOCALID_BRINEY_DEWFORD, Route104_Movement_BrineyExitBoat
	waitmovement 0
	addobject LOCALID_BOAT_DEWFORD
	clearflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
	call Common_EventScript_StopBrineysBoatMusic
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT
	hideobjectat LOCALID_BOAT_R104, MAP_ROUTE104
	copyvar VAR_BRINEY_LOCATION, VAR_0x8008
	copyobjectxytoperm LOCALID_BRINEY_DEWFORD
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 0
	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, Route104_EventScript_DeliverLetterReminder
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, Route104_EventScript_LandedInDewford
	end

Route104_EventScript_DeliverLetterReminder:: @ 81ED1B4
	msgbox Route104_Text_LandedInDewfordDeliverLetter, MSGBOX_DEFAULT
	releaseall
	end

Route104_EventScript_LandedInDewford:: @ 81ED1BE
	msgbox DewfordTown_Text_BrineyLandedInDewford, MSGBOX_DEFAULT
	releaseall
	end

Route104_Movement_SailToDewfordBeforeDadCalls: @ 81ED1C8
	walk_down
	walk_down
	walk_down
	walk_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	step_end

Route104_Movement_SailToDewfordAfterDadCalls: @ 81ED22A
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_down
	walk_down
	step_end

Route104_Movement_SailToDewford: @ 81ED28C
	walk_down
	walk_down
	walk_down
	walk_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_down
	walk_down
	step_end

Route104_Movement_PlayerBoardBoat: @ 81ED34F
	walk_left
	walk_down
	walk_down
	step_end

Route104_Movement_PlayerExitBoat: @ 81ED353
	walk_down
	step_end

Route104_Movement_PlayerMoveForBriney: @ 81ED355
	walk_down
	walk_left
	walk_in_place_fastest_right
	step_end

Route104_Movement_BrineyBoardBoat: @ 81ED359
	walk_down
	walk_down
	step_end

Route104_Movement_BrineyExitBoat: @ 81ED35C
	walk_down
	walk_in_place_fastest_left
	step_end

Percorso5_EventScript_Roger:: @ 81ED35F
	trainerbattle_single TRAINER_ROGER, Percorso5_Text_RogerIntro, Percorso5_Text_RogerDefeat
	msgbox Percorso5_Text_RogerPostBattle, MSGBOX_AUTOCLOSE
	end

Percorso4_EventScript_Athena:: @ 81ED376
	trainerbattle_single TRAINER_ATHENA, Percorso4_Text_AthenaIntro, Percorso4_Text_AthenaDefeat
	msgbox Percorso4_Text_AthenaPostBattle, MSGBOX_AUTOCLOSE
	end


Percorso4_Text_AthenaIntro:
.string "I miei Pokémon vanno d'amore e\n"
.string "d'accordo! Lottiamo!$"

Percorso4_Text_AthenaDefeat:
.string "Interessante! Hai sconfitto il mio\n"
.string "gioco di squadra!$"

Percorso4_Text_AthenaPostBattle:
.string "Ho sentito dire che alcuni Pokémon\n"
.string "non si evolvono se non con Pietre\l"
.string "particolari.$"

Percorso5_EventScript_Tyron:: @ 81ED38D
trainerbattle_single TRAINER_TYRON, Percorso5_Text_TyronIntro, Percorso5_Text_TyronDefeat
msgbox Percorso5_Text_TyronPostBattle, MSGBOX_AUTOCLOSE
end

Route104_EventScript_TryRegisterHaleyAfterBattle:: @ 81ED3CE
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterHaleyAfterBattle
	release
	end

Route104_EventScript_RegisterHaleyAfterBattle:: @ 81ED3DF
	msgbox Route104_Text_HaleyRegister2, MSGBOX_DEFAULT
	register_matchcall TRAINER_HALEY_1
	release
	end

Route104_EventScript_TryRegisterHaley:: @ 81ED3F8
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterHaley
	msgbox Route104_Text_HaleyPostBattle, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_RegisterHaley:: @ 81ED40B
	msgbox Route104_Text_HaleyRegister1, MSGBOX_DEFAULT
	register_matchcall TRAINER_HALEY_1
	release
	end

Route104_EventScript_RematchHaley:: @ 81ED424
	trainerbattle_rematch TRAINER_HALEY_1, Route104_Text_HaleyRematchIntro, Route104_Text_HaleyRematchDefeat
	msgbox Route104_Text_HaleyPostRematch, MSGBOX_AUTOCLOSE
	end

Percorso5_EventScript_Bianca:: @ 81ED43B
trainerbattle_single TRAINER_BIANCA, Percorso5_Text_BiancaIntro, Percorso5_Text_BiancaDefeat
msgbox Percorso5_Text_BiancaPostBattle, MSGBOX_AUTOCLOSE
end

Route104_EventScript_TryRegisterWinstonAfterBattle:: @ 81ED47C
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterWinstonAfterBattle
	release
	end

Route104_EventScript_RegisterWinstonAfterBattle:: @ 81ED48D
	msgbox Route104_Text_WinstonRegister2, MSGBOX_DEFAULT
	register_matchcall TRAINER_WINSTON_1
	release
	end

Route104_EventScript_TryRegisterWinston:: @ 81ED4A6
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterWinston
	msgbox Route104_Text_WinstonPostBattle, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_RegisterWinston:: @ 81ED4B9
	msgbox Route104_Text_WinstonRegister1, MSGBOX_DEFAULT
	register_matchcall TRAINER_WINSTON_1
	release
	end

Route104_EventScript_RematchWinston:: @ 81ED4D2
	trainerbattle_rematch TRAINER_WINSTON_1, Route104_Text_WinstonRematchIntro, Route104_Text_WinstonRematchDefeat
	msgbox Route104_Text_WinstonPostRematch, MSGBOX_AUTOCLOSE
	end

Route104_EventScript_Cindy:: @ 81ED4E9
	msgbox Route104_Text_Cindy, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_TryRegisterCindyAfterBattle:: @ 81ED52A
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterCindyAfterBattle
	release
	end

	Route104_Text_Cindy:
	.string "Fila via, marmocchio! Stiamo\n"
	.string "perlustrando il Bosco Driade!$"

Route104_EventScript_RegisterCindyAfterBattle:: @ 81ED53B
	msgbox Route104_Text_CindyRegister2, MSGBOX_DEFAULT
	register_matchcall TRAINER_CINDY_1
	release
	end

Route104_EventScript_TryRegisterCindy:: @ 81ED554
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterCindy
	release
	end

Route104_EventScript_RegisterCindy:: @ 81ED567
	msgbox Route104_Text_CindyRegister1, MSGBOX_DEFAULT
	register_matchcall TRAINER_CINDY_1
	release
	end

Route104_EventScript_RematchCindy:: @ 81ED580
	trainerbattle_rematch TRAINER_CINDY_1, Route104_Text_CindyRematchIntro, Route104_Text_CindyRematchDefeat
	msgbox Route104_Text_CindyPostRematch, MSGBOX_AUTOCLOSE
	end

Percorso5_EventScript_Leah:: @ 81ED597
trainerbattle_single TRAINER_LEAH, Percorso5_Text_LeahIntro, Percorso5_Text_LeahDefeat
msgbox Percorso5_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
end

Percorso5_EventScript_Joseph:: @ 81ED5B6
trainerbattle_single TRAINER_JOSEPH, Percorso5_Text_JosephIntro, Percorso5_Text_JosephDefeat
msgbox Percorso5_Text_JosephPostBattle, MSGBOX_AUTOCLOSE
end

Percorso4_EventScript_Eli:: @ 81ED5D5
	trainerbattle_single TRAINER_ELI, Percorso4_Text_EliIntro, Percorso4_Text_EliDefeat
	msgbox Percorso4_Text_EliPostBattle, MSGBOX_AUTOCLOSE
	end

Percorso4_Text_EliIntro:
.string "Viaggio da un pò! Vediamo se puoi\n"
.string "confrontarti con la mia esperienza\l"
.string "giovane allenatore!$"

Percorso4_Text_EliDefeat:
.string "Ahahah, che risultato inaspettato,\n"
.string "devo dire!$"

Percorso4_Text_EliPostBattle:
.string "L'esperienza è molto importante e\n"
.string "tu sembri già averne parecchia!$"

Route104_Text_BrineyLivesInSeasideCottage: @ 81ED5EC
	.string "Fila via, marmocchio! Stiamo\n"
	.string "perlustrando il Bosco Driade!$"

Route104_Text_WhatsItLikeAtBottomOfSea: @ 81ED662
	.string "The sea, huh?\p"
	.string "I wonder what it's like at the bottom\n"
	.string "of the sea?$"

Route104_Text_ThrowBallAtWeakenedPokemon: @ 81ED6A2
	.string "If you're going to throw a POKé BALL,\n"
	.string "weaken the wild POKéMON first.\p"
	.string "It will be easier to catch if it's been\n"
	.string "poisoned, burned, or lulled to sleep.$"

Route104_Text_ImNotATrainer: @ 81ED7A2
	.string "Oh, no, I'm not a TRAINER.\p"
	.string "But that's right, if TRAINERS lock eyes,\n"
	.string "it's a challenge to battle.\p"
	.string "If you don't want to battle, stay out\n"
	.string "of their sight.$"

Route104_Text_LikeFillingMouthWithSeedsTakeThis: @ 81ED838
	.string "I like filling my mouth with seeds,\n"
	.string "then spitting them out fast!\p"
	.string "You can have this, so you try it out!\p"
	.string "Use it on a POKéMON, and it will learn\n"
	.string "a move for firing seeds rapidly.$"

Route104_Text_TMsAreOneTimeUse: @ 81ED8E7
	.string "A word of advice!\p"
	.string "A TM, TECHNICAL MACHINE, is good only\n"
	.string "for one-time use.\p"
	.string "Once you use it, it's gone.\n"
	.string "Think twice before using it!$"

Route104_Text_DontNeedThisTakeIt: @ 81ED96A
	.string "This FLOWER SHOP started selling\n"
	.string "saplings recently.\p"
	.string "It made me so happy, I went overboard\n"
	.string "shopping.\p"
	.string "I don't need this WHITE HERB anymore.\n"
	.string "Would you take it, please?$"

Route104_Text_FlowerShopSellingSaplings: @ 81EDA0F
	.string "This FLOWER SHOP started selling\n"
	.string "saplings recently.\p"
	.string "It made me so happy, I went overboard\n"
	.string "shopping. Where should I put them?$"

Route104_Text_MrBrineysCottage: @ 81EDA8C
	.string "MR. BRINEY'S COTTAGE$"

Route104_Text_RouteSignPetalburg: @ 81EDAA1
	.string "ROUTE 1O4\n"
	.string "{RIGHT_ARROW} PETALBURG CITY$"

Route104_Text_RouteSignRustboro: @ 81EDABC
	.string "ROUTE 1O4\n"
	.string "{UP_ARROW} RUSTBORO CITY$"

Route104_Text_PrettyPetalFlowShop: @ 81EDAD6
	.string "PRETTY PETAL FLOWER SHOP$"

Route104_Text_TrainerTipsDoubleBattles: @ 81EDAEF
	.string "TRAINER TIPS\p"
	.string "In the HOENN region there are pairs\n"
	.string "of TRAINERS who challenge others\l"
	.string "for 2-on-2 POKéMON battles called\l"
	.string "DOUBLE BATTLES.\p"
	.string "In a DOUBLE BATTLE, the TRAINER must\n"
	.string "send out two POKéMON, the one at the\l"
	.string "left of the list and the top one.\l"
	.string "Watch how POKéMON are lined up.$"

Route104_Text_MayWeShouldRegister: @ 81EDBFF
	.string "MAY: Oh, hi, {PLAYER}{KUN}!\p"
	.string "DEVON upgraded your POKéNAV with\n"
	.string "the MATCH CALL system, huh?\p"
	.string "We should register each other so we\n"
	.string "can get in contact anytime.$"

Route104_Text_RegisteredMay: @ 81EDC8F
	.string "{PLAYER} registered MAY\n"
	.string "in the POKéNAV.$"

Route104_Text_MayHowsYourPokedex: @ 81EDCB1
	.string "MAY: Oh, by the way, {PLAYER}{KUN},\n"
	.string "how's your POKéDEX coming along?$"

Route104_Text_MayMinesDecentLetsBattle: @ 81EDCED
	.string "Mine's looking pretty decent.\n"
	.string "So…\l"
	.string "How about a little battle?$"

Route104_Text_MayHaventRaisedPokemon: @ 81EDD2A
	.string "MAY: Oh, what's the matter?\p"
	.string "Haven't you caught or raised your\n"
	.string "POKéMON very much?\p"
	.string "That's not very good for a TRAINER!$"

Route104_Text_MayLetsBattle: @ 81EDD9F
	.string "MAY: So, what do you think?\n"
	.string "How about a little battle here?$"

Route104_Text_MayIntro: @ 81EDDDB
	.string "MAY: You just became a TRAINER,\n"
	.string "{PLAYER}{KUN}. I'm not going to lose!$"

Route104_Text_MayDefeat: @ 81EDE18
	.string "Yikes!\n"
	.string "You're better than I expected!$"

Route104_Text_MayPostBattle: @ 81EDE3E
	.string "MAY: I can tell you've gotten pretty\n"
	.string "good with the way you handle POKéMON.\p"
	.string "But instead of only making them\n"
	.string "battle, you should be like MR. BRINEY.\p"
	.string "It's important to become friends with\n"
	.string "POKéMON, too.$"

Route104_Text_BrendanWeShouldRegister: @ 81EDF04
	.string "BRENDAN: Oh, hey, {PLAYER}!\p"
	.string "Cool, you had DEVON install the MATCH\n"
	.string "CALL system on your POKéNAV!\p"
	.string "Let's register each other in our\n"
	.string "POKéNAVS so we can keep in touch.$"

Route104_Text_RegisteredBrendan: @ 81EDFA0
	.string "{PLAYER} registered BRENDAN\n"
	.string "in the POKéNAV.$"

Route104_Text_BrendanHowsYourPokedex: @ 81EDFC6
	.string "BRENDAN: {PLAYER}, how's your POKéDEX?\n"
	.string "Have you filled in any pages yet?$"

Route104_Text_BrendanDoingGreatLetsBattle: @ 81EE009
	.string "Me, I'm doing great!\p"
	.string "Want to check out how good I am with\n"
	.string "a battle?$"

Route104_Text_BrendanNoConfidence: @ 81EE04D
	.string "BRENDAN: What's the matter? Don't have\n"
	.string "any confidence in your POKéMON?$"

Route104_Text_BrendanLetsBattle: @ 81EE094
	.string "BRENDAN: What's up?\n"
	.string "Want to have a battle with me?$"

Route104_Text_BrendanIntro: @ 81EE0C7
	.string "BRENDAN: I know you just became\n"
	.string "a TRAINER, but I won't go easy!$"

Route104_Text_BrendanDefeat: @ 81EE107
	.string "Hmm…\n"
	.string "You're pretty good.$"

Route104_Text_BrendanPostBattle: @ 81EE120
	.string "BRENDAN: You've gotten pretty decent\n"
	.string "at handling POKéMON.\p"
	.string "But, you know, you shouldn't just be\n"
	.string "making POKéMON battle.\p"
	.string "Like MR. BRINEY, it's important to\n"
	.string "become friends with your POKéMON.$"

EventScript_endfirstrivaltiafight::
releaseall
end

Percorso5_EventScript_Tilesx::
lockall
compare VAR_UNUSED_0x40BB, 0
goto_if_gt EventScript_endfirstrivaltiafight
playbgm MUS_ENCOUNTER_MAY, TRUE
applymovement OBJ_EVENT_ID_PLAYER, move_0upwalk
applymovement 30, m1_percorso5
applymovement OBJ_EVENT_ID_PLAYER, m2_percorso5
playse SE_PIN
waitmovement 0
msgbox Text_1tiafirstfight MSGBOX_DEFAULT
applymovement 30, m3_percorso5
playse SE_PIN
waitmovement 0
delay 50
playse SE_BOO
applymovement OBJ_EVENT_ID_PLAYER, m4_percorso5
waitmovement 0
msgbox Text_2tiafirstfight MSGBOX_DEFAULT
closemessage
applymovement 30, m5_percorso5
msgbox Text_3tiafirstfight MSGBOX_DEFAULT
trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TORCHIC, Percorso5_Text_Tia1Defeat
msgbox Text_4tiafirstfight MSGBOX_DEFAULT
closemessage
msgbox Text_5tiafirstfight MSGBOX_DEFAULT
closemessage
applymovement 30, m_pretendtogoaway
delay 30
applymovement OBJ_EVENT_ID_PLAYER, m_frwht
waitmovement 0
applymovement 30, m2_percorso5
playse SE_PIN
delay 40
applymovement OBJ_EVENT_ID_PLAYER, m4_percorso5
playse SE_PIN
waitmovement 0
msgbox Text_6tiafirstfight MSGBOX_DEFAULT
closemessage
applymovement 30, m_returnback
msgbox Text_7tiafirstfight MSGBOX_DEFAULT
playfanfare MUS_OBTAIN_ITEM
waitfanfare
closemessage
msgbox Text_8tiafirstfight MSGBOX_DEFAULT
closemessage
applymovement 30, goawayforreeal
applymovement OBJ_EVENT_ID_PLAYER, m_frwht
waitmovement 0
removeobject 30
setflag FLAG_UNUSED_0x026
savebgm MUS_DUMMY
fadedefaultbgm
setvar VAR_UNUSED_0x40BB, 1
releaseall
end

move_0upwalk:
walk_up
step_end

Percorso5_Text_Tia1Defeat:
.string "Magenta: Ouch! Il mio Gible!\n"
.string "E va bene {PLAYER}, accetto la mia\l"
.string "sconfitta! Sei forte!\l$"

m_returnback:
walk_down
walk_left
walk_left
walk_left
walk_left
step_end

m_frwht:
face_right
step_end

m_pretendtogoaway:
walk_right
walk_right
walk_right
walk_right
step_end

m4_percorso5:
emote_question_mark
step_end

m3_percorso5:
emote_heart
step_end

m2_percorso5:
emote_exclamation_mark
step_end

m1_percorso5:
face_down
emote_exclamation_mark
step_end

m5_percorso5:
walk_down
walk_down
step_end

Text_1tiafirstfight:
.string "Magenta: Oh, {PLAYER}! Che bello\n"
.string "vederti qui!$"

Text_2tiafirstfight:
.string "Magenta: Non sei felice di vedermi?$"

Text_3tiafirstfight:
.string "Magenta: Il mio Gible, sembra\n"
.string "voglia combattere contro di te.\l"
.string "{PLAYER}, ti ho già visto lottare\l"
.string "contro Indaco e conosco tutte le\l"
.string "tue mosse. Vediamo se riuscirai a\l"
.string "sconfiggere il mio Gible!$"

Text_4tiafirstfight:
.string "Magenta: Il mio Gible! Ha perso?\n"
.string "Che dico. Abbiamo perso insieme.\l"
.string "Ti ringrazio {PLAYER}, mi hai fatto\l"
.string "capire che devo catturare altre\l"
.string "specie di Pokémon, se voglio che\l"
.string "un giorno Camy mi rispetti come\l"
.string "allenatrice!$"

Text_5tiafirstfight:
.string "Magenta: Oh, quasi dimenticavo!\n"
.string "Scommetto che al Prof. Sherman\l"
.string "siano piaciuti i dolci che gli hai\l"
.string "portato. Quell'uomo è un golosone!\l"
.string "Sono contenta che ti abbia dato un\l"
.string "Pokédex, vedrai che con quello\l"
.string "viaggiare diventerà ancora più\l"
.string "divertente! Anche io ne ho uno, mi\l"
.string "è stato dato poco tempo prima di\l"
.string "te. Sono sicura che anche Indaco\l"
.string "ne abbia ricevuto uno. Fa tanto il\l"
.string "tosto ma sono certa che anche lui\l"
.string "sia andato a trovare il Prof.\l"
.string "Sherman!$"

Text_6tiafirstfight:
.string "Magenta: Hmm, che stupida! Questo\n"
.string "potrebbe tornagli utile!$"

Text_7tiafirstfight:
.string "Magenta: {PLAYER}, ho un oggetto\n"
.string "che potrebbe esserti utile. Si\l"
.string "chiama Detector. Questo strumento\l"
.string "riesce a rilevare ciò che si\l"
.string "nasconde in giro!$"

Text_8tiafirstfight:
.string "Magenta: Adesso, sarà meglio che\n"
.string "vada. Comunque, sono sicura che\l"
.string "riusciremo a raggiungere i nostri\l"
.string "obiettivi. Abbiamo una Medaglia\l"
.string "entrambi e siamo in viaggio da\l"
.string "pochissimo tempo! In bocca al lupo\l"
.string "per la sfida alla Palestra di\l"
.string "Hedgen!$"

Percorso5_EventScript_Tiledx::
lockall
compare VAR_UNUSED_0x40BB, 0
goto_if_gt EventScript_endfirstrivaltiafight
playbgm MUS_ENCOUNTER_MAY, TRUE
applymovement OBJ_EVENT_ID_PLAYER, M_zeroo
waitmovement 0
applymovement 30, m1_percorso5
applymovement OBJ_EVENT_ID_PLAYER, m2_percorso5
playse SE_PIN
waitmovement 0
msgbox Text_1tiafirstfight MSGBOX_DEFAULT
applymovement 30, m3_percorso5
playse SE_PIN
waitmovement 0
delay 50
playse SE_BOO
applymovement OBJ_EVENT_ID_PLAYER, m4_percorso5
waitmovement 0
msgbox Text_2tiafirstfight MSGBOX_DEFAULT
closemessage
applymovement 30, m5_percorso5
msgbox Text_3tiafirstfight MSGBOX_DEFAULT
trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TORCHIC, Percorso5_Text_Tia1Defeat
msgbox Text_4tiafirstfight MSGBOX_DEFAULT
closemessage
msgbox Text_5tiafirstfight MSGBOX_DEFAULT
closemessage
applymovement 30, m_pretendtogoaway
delay 30
applymovement OBJ_EVENT_ID_PLAYER, m_frwht
waitmovement 0
applymovement 30, m2_percorso5
playse SE_PIN
delay 40
applymovement OBJ_EVENT_ID_PLAYER, m4_percorso5
playse SE_PIN
waitmovement 0
msgbox Text_6tiafirstfight MSGBOX_DEFAULT
closemessage
applymovement 30, m_returnback
msgbox Text_7tiafirstfight MSGBOX_DEFAULT
playfanfare MUS_OBTAIN_ITEM
waitfanfare
closemessage
msgbox Text_8tiafirstfight MSGBOX_DEFAULT
closemessage
applymovement 30, goawayforreeal
applymovement OBJ_EVENT_ID_PLAYER, m_frwht
waitmovement 0
removeobject 30
setflag FLAG_UNUSED_0x026
savebgm MUS_DUMMY
fadedefaultbgm
setvar VAR_UNUSED_0x40BB, 1
releaseall
end

goawayforreeal:
walk_right
walk_right
walk_right
walk_right
walk_right
walk_right
step_end

M_zeroo:
walk_left
walk_up
face_up
step_end

Percorso5_Text_AshleyIntro:
.string "Che giornata fantastica! Mi mette\n"
.string "proprio di buon umore!$"

Percorso5_Text_AshleyDefeat:
.string "Perdere, mi rovina l'umore.$"

Percorso5_Text_AshleyPostBattle:
.string "La luce del Sole migliora l'umore\n"
.string "grazie alla Vitamina D.$"

Percorso5_Text_FlintIntro:
.string "E' il momento giusto per una\n"
.string "sfida!$"

Percorso5_Text_FlintDefeat:
.string "Tu ed i tuoi Pokémon sembrate in\n"
.string "ottima forma!$"

Percorso5_Text_FlintPostBattle:
.string "Ricordati, tratta con cura i tuoi\n"
.string "Pokémon. Se sono esausti, portali\l"
.string "al Centro Pokémon.$"

Percorso5_Text_KaiIntro:
.string "Dove si compra un Amo Buono?$"

Percorso5_Text_KaiDefeat:
.string "I miei Pokémon hanno dato il loro\n"
.string "meglio.$"

Percorso5_Text_KaiPostBattle:
.string "Volevo acquistare un Amo Buono, ma\n"
.string "sembra impossibile trovarlo al\l"
.string "Poké Market!$"

Percorso5_Text_RogerIntro:
.string "Okay, lottiamo, anche perché è una\n"
.string "giornata stupenda!$"

Percorso5_Text_RogerDefeat:
.string "E' come se si fosse rotta la canna\n"
.string "da pesca!"

Percorso5_Text_RogerPostBattle:
.string "Devo dire, che sei formidabile per\n"
.string "la tua età.$"

Percorso5_Text_LeahIntro:
.string "Non ho paura degli spettri, i tuoi\n"
.string "Pokémon non mi spaventano!$"

Percorso5_Text_LeahDefeat:
.string "I miei Pokémon hanno paura di te!$"

Percorso5_Text_LeahPostBattle:
.string "Vorresti visitare una casa\nabbandonata?$"

Percorso5_Text_JosephIntro:
.string "Suonare la chitarra è divertente,\n"
.string "però ora ho bisogno di lottare!$"

Percorso5_Text_JosephDefeat:
.string "Tornerò a suonare la chitarra! Ok!$"

Percorso5_Text_JosephPostBattle:
.string "Ogni tanto, bisogna staccare dalle\n"
.string "lotte e prendersi una bella pausa.$"

Percorso5_Text_BiancaIntro:
.string "Sì, lottiamo, è così che si fa\n"
.string "esperienza!$"

Percorso5_Text_BiancaDefeat:
.string "Con così poca esperienza alle\n"
.string "spalle, sei così abile?$"

Percorso5_Text_BiancaPostBattle:
.string "Lottare, richiede molto talento.\n"
.string "Alcuni allenatori, eccellono in\l"
.string "questo.$"

Percorso5_Text_TyronIntro:
.string "Il Sole splende come non ha mai..?$"

Percorso5_Text_TyronDefeat:
.string "Splenduto..? Spleso? Ho perso!..$"

Percorso5_Text_TyronPostBattle:
.string "Non so come si faccia ad amare la\n"
.string "pioggia.$"
