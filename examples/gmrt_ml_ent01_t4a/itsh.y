/* ======================================================================== */
/*	コベルコ建機様向け用　稼動機管理システム								*/
/*	ファイル名	：	itsh.y													*/
/*	説明		：	メール電文の構文解析									*/
/* ------------------------------------------------------------------------ */
/*	作成	SKCS	2009.02.01												*/
/*	更新																	*/
/*			KSC		2011.10.25	ミニ流用：国外／オーブコム２対応			*/
/*																			*/
/* ======================================================================== */

%{
#include <stdio.h>
#include <stdlib.h>
#include "merit_bat.h"
#include <time.h>

char cmd_line[BODY_LINE_MAX_LEN+1];

extern CMD_COM_PARAM	G_CMD_COM_PARAM;
extern char *itc_strdup(const char *);

%}

%union {
	int intval;
	double dblval;
	char *strval;
}

%token LT_DOUBLE
%token LT_COMMA
%token LT_ON
%token LT_OFF
%token LT_OKNG
%token LT_POS_ERR
%token LT_IP_ADDR
%token LT_TEXT
%token LT_HEX

%token LT_INT2
%token LT_INT10
%token LT_INTEGER

%token CMD_TOKEN_H
%token CMD_TOKEN_SC
%token CMD_TOKEN_SA
%token CMD_TOKEN_BT
%token CMD_TOKEN_A
%token CMD_TOKEN_EG
%token CMD_TOKEN_AM
%token CMD_TOKEN_AMON
%token CMD_TOKEN_AMOF
%token CMD_TOKEN_CL
%token CMD_TOKEN_CM0
%token CMD_TOKEN_CM1
%token CMD_TOKEN_D0
%token CMD_TOKEN_D1
%token CMD_TOKEN_D2
%token CMD_TOKEN_D3
%token CMD_TOKEN_M0
%token CMD_TOKEN_M1
%token CMD_TOKEN_M2
%token CMD_TOKEN_M3
%token CMD_TOKEN_M4
%token CMD_TOKEN_M5
%token CMD_TOKEN_M6
%token CMD_TOKEN_M7
%token CMD_TOKEN_M8

%token CMD_TOKEN_T
%token CMD_TOKEN_P
%token CMD_TOKEN_I
%token CMD_TOKEN_R
%token CMD_TOKEN_C
%token CMD_TOKEN_N
%token CMD_TOKEN_F
%token CMD_TOKEN_W
%token CMD_TOKEN_U
%token CMD_TOKEN_J
%token CMD_TOKEN_EC
%token CMD_TOKEN_FC
%token CMD_TOKEN_HC
%token CMD_TOKEN_LC
%token CMD_TOKEN_OV
%token CMD_TOKEN_FT
%token CMD_TOKEN_FS
%token CMD_TOKEN_HS
%token CMD_TOKEN_HE
%token CMD_TOKEN_HF
%token CMD_TOKEN_HH
%token CMD_TOKEN_HL
%token CMD_TOKEN_AH
%token CMD_TOKEN_PN
%token CMD_TOKEN_VR

%token CMD_TOKEN_XX
%token CMD_TOKEN_SD_1
%token CMD_TOKEN_SD_2

%token CMD_TOKEN_NENPI

%token CMD_TOKEN_V
%token CMD_TOKEN_EA
%token CMD_TOKEN_PA
%token CMD_TOKEN_PB
%token CMD_TOKEN_PC
%token CMD_TOKEN_UA
%token CMD_TOKEN_UB
%token CMD_TOKEN_SW
%token CMD_TOKEN_ST
%token CMD_TOKEN_MC
%token CMD_TOKEN_MT
%token CMD_TOKEN_DA
%token CMD_TOKEN_SL
%token CMD_TOKEN_TD
%token CMD_TOKEN_AE
%token CMD_TOKEN_AR
%token CMD_TOKEN_X1

%token TOKEN_ERROR

%token LT_HEADER_ONE_LINE
%token LT_RETURN_HEADER
%token LT_RETURN
%token LT_RETURN_2

%token CMD_TOKEN_HA
%token CMD_TOKEN_LK
%token CMD_TOKEN_YD
%token CMD_TOKEN_OT
%token CMD_TOKEN_M
%token CMD_TOKEN_JH
%token CMD_TOKEN_JS
%token CMD_TOKEN_JE
%token CMD_TOKEN_AB
%token CMD_TOKEN_SS
%token CMD_TOKEN_SR
%token CMD_TOKEN_SG
%token CMD_TOKEN_SU
%token CMD_TOKEN_HD
%token CMD_TOKEN_HQ
%token CMD_TOKEN_HP
%token CMD_TOKEN_DG
%token CMD_TOKEN_DU
%token CMD_TOKEN_DC
%token CMD_TOKEN_DR
%token CMD_TOKEN_ASTRSK1
%token CMD_TOKEN_ASTRSK2
%token CMD_TOKEN_NUMSIGN
%token CMD_TOKEN_FD
%token CMD_TOKEN_FR
%token CMD_TOKEN_FQ
%token CMD_TOKEN_VE
%token CMD_TOKEN_TC
%token CMD_TOKEN_RR
%token CMD_TOKEN_SSID
%token CMD_TOKEN_KL

%type	<strval>	LT_HEADER_ONE_LINE
%type	<strval>	LT_DOUBLE
%type	<strval>	LT_ON
%type	<strval>	LT_OFF
%type	<strval>	LT_OKNG
%type	<strval>	LT_IP_ADDR
%type	<strval>	LT_POS_ERR
%type	<strval>	LT_NUMERIC
%type	<strval>	LT_INTEGER
%type	<strval>	LT_HEX
%type	<strval>	LT_INT2
%type	<strval>	LT_INT10
%type	<strval>	LT_INTVAL
%type	<strval>	CMD_TOKEN_XX
%type	<strval>	LT_TEXT
%type	<strval>	LT_TEXT_EX
%type	<strval>	CMD_TOKEN_X1


%type	<strval>	CMD_TOKEN_DA
%type	<strval>	CMD_TOKEN_HA
%type	<strval>	CMD_TOKEN_LK
%type	<strval>	CMD_TOKEN_YD
%type	<strval>	CMD_TOKEN_OT
%type	<strval>	CMD_TOKEN_M
%type	<strval>	CMD_TOKEN_JH
%type	<strval>	CMD_TOKEN_JS
%type	<strval>	CMD_TOKEN_JE
%type	<strval>	CMD_TOKEN_AB
%type	<strval>	CMD_TOKEN_SS
%type	<strval>	CMD_TOKEN_SR
%type	<strval>	CMD_TOKEN_SG
%type	<strval>	CMD_TOKEN_SU
%type	<strval>	CMD_TOKEN_HD
%type	<strval>	CMD_TOKEN_HQ
%type	<strval>	CMD_TOKEN_HP
%type	<strval>	CMD_TOKEN_DG
%type	<strval>	CMD_TOKEN_DU
%type	<strval>	CMD_TOKEN_DC
%type	<strval>	CMD_TOKEN_DR
%type	<strval>	CMD_TOKEN_FD
%type	<strval>	CMD_TOKEN_FR
%type	<strval>	CMD_TOKEN_FQ
%type	<strval>	CMD_TOKEN_VE
%type	<strval>	CMD_TOKEN_TC
%type	<strval>	CMD_TOKEN_RR
%type	<strval>	CMD_TOKEN_SSID
%type	<strval>	CMD_TOKEN_KL

%%

/*--------------------------------------------------------------------------*/
/*	メール定義																*/
/*--------------------------------------------------------------------------*/
/*	メール定義																*/
MAIL : 
	MAIL_HEADER _MAIL_BODY 
	{
		_MAIL();
	}
	| error
	{
		_MLTYPE_XXXX(1);
	}
	| MAIL_HEADER error
	{
		_MLTYPE_XXXX(2);
	}
	| MAIL_HEADER _MAIL_BODY error
	{
		_MLTYPE_XXXX(3);
	}
;

/*	メールヘッダ定義														*/
MAIL_HEADER :
	MAIL_HEADER_LINES LT_RETURN_HEADER {
		_MAIL_HEADER();
	}
;

/*	メールヘッダライン定義													*/
MAIL_HEADER_LINES :
	  LT_HEADER_ONE_LINE 
	| MAIL_HEADER_LINES LT_HEADER_ONE_LINE 
;

_MAIL_BODY :
	  MAIL_BODY
;

MAIL_BODY :
	  MLTYPE_DAILY_DAYTIME
	| MLTYPE_ONLY_POS
	| MLTYPE_DAILY_NIGHT_OPE
	| MLTYPE_DAILY_NIGHT_NON_OPE
	| MLTYPE_ALARM_SC
	| MLTYPE_ALARM_SA
	| MLTYPE_ALARM_BT
	| MLTYPE_RESPONSE_RT
	| MLTYPE_RESPONSE_AM
	| MLTYPE_RESPONSE_CL
	| MLTYPE_RESPONSE_CM0
	| MLTYPE_RESPONSE_CM1
	| MLTYPE_RESPONSE_CT0
	| MLTYPE_RESPONSE_CT1
	| MLTYPE_DAILY_NIGHT_EXCEPTION
	| MLTYPE_AMNG
	| MLTYPE_HSOK
	| MLTYPE_HSNG
	| MLTYPE_HEOK
	| MLTYPE_HENG
	| MLTYPE_HFOK
	| MLTYPE_HFNG
	| MLTYPE_HHOK
	| MLTYPE_HHNG
	| MLTYPE_HLOK
	| MLTYPE_HLNG
	| MLTYPE_RESPONSE_AC
	| MLTYPE_WARNING
	| MLTYPE_SD
	| MLTYPE_RM
	| MLTYPE_XX_V7
	| MLTYPE_TD
	| MLTYPE_DAILY_OPE
	| MLTYPE_DAILY_NOPE
	| MLTYPE_ALARM_SS
	| MLTYPE_ALARM_SR
	| MLTYPE_ALARM_SG
	| MLTYPE_ALARM_SU
	| MLTYPE_RES_REMOTE_DL
	| MLTYPE_ASTRSK
	| MLTYPE_FDFD
	| MLTYPE_HDHQHP
	| MLTYPE_LKOK
	| MLTYPE_AR
	| MLTYPE_AE
	| MLTYPE_RR
	| MLTYPE_SSID
	| MLTYPE_KL
;

/*--------------------------------------------------------------------------*/
/*	メールタイプ定義														*/
/*--------------------------------------------------------------------------*/
/*	夜間バッチ定義															*/
MLTYPE_DAILY_NIGHT_OPE :
	CMD_LINE_POS 
	CMD_LINES_EGN_TP 
	CMD_LINES_IDOL_I 
	CMD_LINES_RUN_R 
	CMD_LINES_HIREACH_C 
	CMD_LINES_NIBURA_N 
	CMD_LINE_HOUR_METER 
	CMD_LINES_FUEL_F 
	CMD_LINES_ENGN_W 
	CMD_LINES_PUMP_U 
	CMD_LINES_KADO_J 
	CMD_LINES_AREA_NAIGAI_A 
	CMD_LINES_ENGN_OIL_EC 
	CMD_LINES_FUEL_FILTER_FC 
	CMD_LINES_SADO_FILTER_HC 
	CMD_LINES_SADO_CHANGE_LC 
	CMD_LINES_OVER_OV 
	CMD_LINES_FUEL_ONDO_FT 
	CMD_LINES_FUEL_STATUS_FS 
	CMD_LINES_NENPI
	CMD_SET_TIER4A_V7
	CMD_LINES_SL
	CMD_LINES_VE
	CMD_LINES_TD
	CMD_LINES_X1
	CMD_LINES_NUMSIGN
	{
		_MLTYPE_DAILY_NIGHT_OPE();
	}
;


/*	位置情報のみ（ITCにより異なる）											*/
MLTYPE_ONLY_POS :
	CMD_LINE_POS 
	{
		_MLTYPE_ONLY_POS();
	}
;


/*	夜間バッチ(非稼働)定義													*/
MLTYPE_DAILY_NIGHT_NON_OPE :
	CMD_LINE_POS 
	CMD_LINES_AREA_NAIGAI_A 
	CMD_LINES_VE
	CMD_LINES_TD
	CMD_LINES_NUMSIGN
	{
		_MLTYPE_DAILY_NIGHT_NON_OPE();
	}
;

/*	昼間バッチ定義															*/
MLTYPE_DAILY_DAYTIME :
	CMD_LINE_POS 
	CMD_LINES_FUEL_F 
	CMD_LINES_NUMSIGN
	{
		_MLTYPE_DAILY_DAYTIME();
	}
;

/*	夜間バッチ(例外)定義													*/
/*	※例外はTP省略不可(としないと非稼動A省略と重複)。実ログから判断			*/
MLTYPE_DAILY_NIGHT_EXCEPTION :
	CMD_LINE_POS 
	_CMD_LINES_EGN_TP 
	CMD_LINES_NUMSIGN
	{
		_MLTYPE_DAILY_NIGHT_EXCEPTION();
	}
;


/*	機械状態問い合わせ(RT応答)												*/
MLTYPE_RESPONSE_RT :
	CMD_LINE_POS 
	CMD_LINE_EG 
	CMD_LINES_FUEL_F 
	CMD_LINES_FUEL_ONDO_FT 
	CMD_LINES_FUEL_STATUS_FS 
	CMD_LINES_XX
	{
		_MLTYPE_RESPONSE_RT();
	}
;

/*	侵入警報定義															*/
MLTYPE_ALARM_SC :
	CMD_LINE_ALARM_SC 
	{
		_MLTYPE_ALARM_SC();
	}
;

/*	エリア外警報定義														*/
MLTYPE_ALARM_SA :
	CMD_LINE_ALARM_SA 
	CMD_LINE_POS 
	{
		_MLTYPE_ALARM_SA();
	}
;

/*	バッテリーはずし警報定義												*/
MLTYPE_ALARM_BT :
	CMD_LINE_ALARM_BT 
	CMD_LINE_POS 
	{
		_MLTYPE_ALARM_BT();
	}
;


/*	侵入警報有効時間設定(AM応答)											*/
MLTYPE_RESPONSE_AM :
	CMD_LINE_AM_OF
	CMD_LINE_AM_ON
	CMD_LINE_AM
	{
		_MLTYPE_RESPONSE_AM();
	}
;

/*	エリア設定(CL応答)														*/
MLTYPE_RESPONSE_CL :
	CMD_LINE_CL 
	{
		_MLTYPE_RESPONSE_CL();
	}
;

/*	通信停止設定(CM0応答)														*/
MLTYPE_RESPONSE_CM0 :
	CMD_LINE_CM0 
	{
		_MLTYPE_RESPONSE_CM0();
	}
;

/*	通信再開設定(CM1応答)														*/
MLTYPE_RESPONSE_CM1 :
	CMD_LINE_CM1 
	{
		_MLTYPE_RESPONSE_CM1();
	}
;

/*	通信テスト(CT0応答)														*/
MLTYPE_RESPONSE_CT0 :
	CMD_LINE_POS 
	CMD_LINE_D0 
	CMD_LINE_D1 
	CMD_LINE_D2 
	CMD_LINE_D3 
	CMD_LINES_FUEL_F 
	{
		_MLTYPE_RESPONSE_CT0();
	}
;

/*	通信量確認(CT1応答)														*/
MLTYPE_RESPONSE_CT1 :
	CMD_LINE_M0 
	CMD_LINE_M1 
	CMD_LINE_M2 
	CMD_LINE_M3 
	CMD_LINE_M4 
	CMD_LINE_M5 
	CMD_LINE_M6 
	CMD_LINE_M7 
	CMD_LINE_M8 
	{
		_MLTYPE_RESPONSE_CT1();
	}
;

/*	時間外エンジン始動設定応答(AMNG)	*/
MLTYPE_AMNG :
	CMD_LINE_AMNG
	{
		_MLTYPE_AMNG();
	}
;

/*	アワメータ変更OK					*/
MLTYPE_HSOK :
	CMD_LINE_HSOK
	{
		_MLTYPE_HSOK();
	}
;

/*	アワメータ変更NG					*/
MLTYPE_HSNG :
	CMD_LINE_HSNG
	{
		_MLTYPE_HSNG();
	}
;

/*	エンジンオイル交換残時間変更OK					*/
MLTYPE_HEOK :
	CMD_LINE_HEOK
	{
		_MLTYPE_HEOK();
	}
;

/*	エンジンオイル交換残時間変更NG					*/
MLTYPE_HENG :
	CMD_LINE_HENG
	{
		_MLTYPE_HENG();
	}
;

/*	燃料フィルタ交換残時間変更OK					*/
MLTYPE_HFOK :
	CMD_LINE_HFOK
	{
		_MLTYPE_HFOK();
	}
;

/*	燃料フィルタ交換残時間変更NG					*/
MLTYPE_HFNG :
	CMD_LINE_HFNG
	{
		_MLTYPE_HFNG();
	}
;

/*	作動油フィルタ交換残時間変更OK					*/
MLTYPE_HHOK :
	CMD_LINE_HHOK
	{
		_MLTYPE_HHOK();
	}
;

/*	作動油フィルタ交換残時間変更NG					*/
MLTYPE_HHNG :
	CMD_LINE_HHNG
	{
		_MLTYPE_HHNG();
	}
;

/*	作動油交換残時間変更OK					*/
MLTYPE_HLOK :
	CMD_LINE_HLOK
	{
		_MLTYPE_HLOK();
	}
;

/*	作動油交換残時間変更NG					*/
MLTYPE_HLNG :
	CMD_LINE_HLNG
	{
		_MLTYPE_HLNG();
	}
;

/*	故障来歴応答	*/
MLTYPE_RESPONSE_AC :
	CMD_LINES_AH
	CMD_LINES_PN
	CMD_LINES_VR
	{
		_MLTYPE_RESPONSE_AC();
	}
;

/*	自己診断メール	*/
MLTYPE_WARNING :
	_CMD_LINES_XX
	{
		_MLTYPE_XX();
	}
;

/*	*/
MLTYPE_SD :
		CMD_LINE_SD_1
		CMD_LINES_SD_2
		CMD_LINE_SD_3
	{
		_MLTYPE_SD();
	}
;

MLTYPE_RM :
		CMD_LINE_PN
		CMD_LINE_V
		CMD_LINE_EA
		CMD_LINE_PA
		CMD_LINE_PB
		CMD_LINE_PC
		CMD_LINE_UA
		CMD_LINE_UB
		CMD_LINE_ST
	{
		_MLTYPE_RM();
	}
;

MLTYPE_XX_V7 :
		CMD_LINE_XX_V7
	{
		_MLTYPE_XX_V7();
	}
;

MLTYPE_TD :
		CMD_LINE_RES_TD
	{
		_MLTYPE_TD();
	}
;

/*	１０型バッチ定義(稼働)									*/
MLTYPE_DAILY_OPE :
	CMD_LINE_POS 
	CMD_LINE_HA 
	CMD_LINE_AREA_NAIGAI_A 
	CMD_LINE_LK 
	CMD_LINE_TD
	CMD_LINE_YD
	CMD_LINE_OT
	CMD_LINE_M
	CMD_LINE_HOUR_METER 
	CMD_LINE_ENGN_OIL_EC 
	CMD_LINE_FUEL_FILTER_FC 
	CMD_LINE_SADO_FILTER_HC 
	CMD_LINE_SADO_CHANGE_LC 
	CMD_LINE_FUEL_F 
	CMD_LINE_FUEL_ONDO_FT 
	CMD_LINE_FUEL_STATUS_FS 
	CMD_LINE_SL
	CMD_LINE_IDOL_I 
	CMD_LINE_RUN_R 
	CMD_LINE_NIBURA_N 
	CMD_LINE_HIREACH_C 
	CMD_LINE_OVER_OV 
	CMD_LINE_SW
	CMD_LINE_ENGN_W 
	CMD_LINE_PUMP_U 
	CMD_LINE_DA
	CMD_LINE_MC
	CMD_LINE_MT
	CMD_LINE_JH
	CMD_LINE_JS
	CMD_LINE_JE
	CMD_LINE_AB
	CMD_LINES_VE
	CMD_LINES_TC
	CMD_LINES_X1
	CMD_LINES_NUMSIGN
	{
		_MLTYPE_DAILY_OPE();
	}
;

/*	１０型バッチ定義(非稼働)									*/
MLTYPE_DAILY_NOPE :
	CMD_LINE_POS 
	CMD_LINE_HA 
	CMD_LINE_AREA_NAIGAI_A 
	CMD_LINE_TD
	CMD_LINE_YD
	CMD_LINES_VE
	CMD_LINES_NUMSIGN
	{
		_MLTYPE_DAILY_NOPE();
	}
;

/*	SIMカード抜去警報定義												*/
MLTYPE_ALARM_SS :
	CMD_LINE_SS 
	CMD_LINE_POS 
	{
		_MLTYPE_ALARM_SS();
	}
;

/*	通信アンテナ切断警報定義												*/
MLTYPE_ALARM_SR :
	CMD_LINE_SR 
	CMD_LINE_POS 
	{
		_MLTYPE_ALARM_SR();
	}
;

/*	GPSアンテナ切断警報定義												*/
MLTYPE_ALARM_SG :
	CMD_LINE_SG 
	CMD_LINE_POS 
	{
		_MLTYPE_ALARM_SG();
	}
;

/*	VCU通信不能警報定義												*/
MLTYPE_ALARM_SU :
	CMD_LINE_SU 
	CMD_LINE_POS 
	{
		_MLTYPE_ALARM_SU();
	}
;

/*	遠隔DL応答												*/
MLTYPE_RES_REMOTE_DL :
	CMD_LINE_RES_REMOTE_DL 
	{
		_MLTYPE_RES_REMOTE_DL();
	}
;

/*	汎用メールI/F												*/
MLTYPE_ASTRSK :
	 CMD_LINE_ASTRSK1
	 _CMD_LINES_ASTRSK2
	{
		_MLTYPE_ASTRSK();
	}
;

/*	故障診断応答												*/
MLTYPE_FDFD :
	_CMD_LINES_FDFQFR
	CMD_LINES_NUMSIGN
	{
		_MLTYPE_FDFR();
	}
;


/*	健康診断応答												*/
MLTYPE_HDHQHP :
	_CMD_LINES_HDHQHP
	CMD_LINES_NUMSIGN
	{
		_MLTYPE_HDHQHP();
	}
;

/*	遠隔ロック設定応答											*/
MLTYPE_LKOK :
	CMD_LINE_LKOK
	{
		_MLTYPE_LKOK();
	}
;

/* 衝突軽減レポート */
MLTYPE_AR :
	_CMD_LINES_AR
	{
		_MLTYPE_AR();
	}
;


/* 衝突軽減機能切り替え情報 */
MLTYPE_AE :
	_CMD_LINES_AE
	{
		_MLTYPE_AE();
	}
;

/* 再生診断 */
MLTYPE_RR :
	_CMD_LINES_RR
	{
		_MLTYPE_RR();
	}
;

/* SSID書込み */
MLTYPE_SSID :
	CMD_LINE_SSID
	{
		_MLTYPE_SSID();
	}
;

/* K-LOAD作業データ */
MLTYPE_KL :
	_CMD_LINES_KL
	{
		_MLTYPE_KL();
	}
;

/*--------------------------------------------------------------------------*/
/*	コマンド(省略行)定義													*/
/*	複数行の解析文に省略を加えても良いのだがシフト還元衝突「shift/reduce」	*/
/*	が発生するため、省略の構文を分ける										*/
/*--------------------------------------------------------------------------*/
CMD_LINES_EGN_TP :
	|	_CMD_LINES_EGN_TP
;

CMD_LINES_AH :
	_CMD_LINES_AH
;

CMD_LINES_XX :
	|	_CMD_LINES_XX
;

CMD_LINES_PN :
	|	_CMD_LINES_PN
;

CMD_LINES_VR :
	|	_CMD_LINES_VR
;

CMD_LINES_SD_2 :
	|	_CMD_LINES_SD_2
;

CMD_LINES_KADO_J :
	|	CMD_LINE_KADO_J
;

CMD_LINES_AREA_NAIGAI_A :
	|	CMD_LINE_AREA_NAIGAI_A
;

CMD_LINES_ENGN_OIL_EC :
	|	CMD_LINE_ENGN_OIL_EC
;

CMD_LINES_FUEL_FILTER_FC :
	|	CMD_LINE_FUEL_FILTER_FC
;

CMD_LINES_SADO_FILTER_HC :
	|	CMD_LINE_SADO_FILTER_HC
;

CMD_LINES_SADO_CHANGE_LC :
	|	CMD_LINE_SADO_CHANGE_LC
;

CMD_LINES_OVER_OV :
	|	CMD_LINE_OVER_OV
;

CMD_LINES_FUEL_ONDO_FT :
	|	CMD_LINE_FUEL_ONDO_FT
;

CMD_LINES_FUEL_STATUS_FS :
	|	CMD_LINE_FUEL_STATUS_FS
;

CMD_LINES_NENPI :
	|	CMD_LINE_NENPI
;

CMD_LINES_IDOL_I :
	|	CMD_LINE_IDOL_I
;

CMD_LINES_RUN_R :
	|	CMD_LINE_RUN_R
;

CMD_LINES_HIREACH_C :
	|	CMD_LINE_HIREACH_C
;

CMD_LINES_NIBURA_N :
	|	CMD_LINE_NIBURA_N
;

CMD_LINES_FUEL_F :
	|	CMD_LINE_FUEL_F
;

CMD_LINES_ENGN_W :
	|	CMD_LINE_ENGN_W
;

CMD_LINES_PUMP_U :
	|	CMD_LINE_PUMP_U
;

CMD_SET_TIER4A_V7 :
	|	_CMD_SET_TIER4A_V7
;

CMD_LINES_SL :
	|	CMD_LINE_SL
;

CMD_LINES_TD :
	|	CMD_LINE_TD
;

CMD_LINES_X1 :
	|	_CMD_LINES_X1
;

CMD_LINES_NUMSIGN :
	|	_CMD_LINES_NUMSIGN
;

CMD_LINES_VE :
	|	CMD_LINE_VE
;

CMD_LINES_TC :
	|	CMD_LINE_TC
;

/*--------------------------------------------------------------------------*/
/*	コマンド(複数行)定義														*/
/*--------------------------------------------------------------------------*/
_CMD_LINES_EGN_TP :
	 	CMD_LINE_EGN_T
	| 	CMD_LINE_EGN_P
	|	_CMD_LINES_EGN_TP
		CMD_LINE_EGN_T
	|	_CMD_LINES_EGN_TP
		CMD_LINE_EGN_P
;

_CMD_LINES_AH :
		_CMD_LINES_AH 
		CMD_LINE_AH
	| 	CMD_LINE_AH
;

_CMD_LINES_XX :
		_CMD_LINES_XX 
		CMD_LINE_XX
	|	CMD_LINE_XX
;

_CMD_LINES_PN :
		_CMD_LINES_PN
		CMD_LINE_PN
	|	CMD_LINE_PN
;

_CMD_LINES_VR :
		_CMD_LINES_VR
		CMD_LINE_VR
	|	CMD_LINE_VR
;

_CMD_LINES_SD_2 :
		_CMD_LINES_SD_2
		CMD_LINE_SD_2
	|	CMD_LINE_SD_2
;


_CMD_LINES_X1 :
	 	CMD_LINE_X1
	|	_CMD_LINES_X1
		CMD_LINE_X1
;

_CMD_LINES_ASTRSK2 :
	 	CMD_LINE_ASTRSK2
	|	_CMD_LINES_ASTRSK2
		CMD_LINE_ASTRSK2
;

_CMD_LINES_NUMSIGN :
		CMD_LINE_NUMSIGN
	|	_CMD_LINES_NUMSIGN
		CMD_LINE_NUMSIGN
;

_CMD_LINES_FDFQFR :
		CMD_LINE_FD
	|	CMD_LINE_FQ
	|	CMD_LINE_FR
	|	_CMD_LINES_FDFQFR
		CMD_LINE_FQ
	|	_CMD_LINES_FDFQFR
		CMD_LINE_FR
;


_CMD_LINES_HDHQHP :
		CMD_LINE_HD
	|	CMD_LINE_HQ
	|	CMD_LINE_HP
	|	_CMD_LINES_HDHQHP
		CMD_LINE_HQ
	|	_CMD_LINES_HDHQHP
		CMD_LINE_HP
;

_CMD_LINES_AE :
		CMD_LINE_AE
	|	_CMD_LINES_AE
		CMD_LINE_AE
;

_CMD_LINES_AR :
		CMD_LINE_AR
	|	_CMD_LINES_AR
		CMD_LINE_AR
;

_CMD_LINES_RR :
		CMD_LINE_RR
	|	_CMD_LINES_RR
		CMD_LINE_RR
;

_CMD_LINES_KL :
		CMD_LINE_KL
	|	_CMD_LINES_KL
		CMD_LINE_KL
;

/*--------------------------------------------------------------------------*/
/*	コマンド(複数行セット)定義												*/
/*--------------------------------------------------------------------------*/
_CMD_SET_TIER4A_V7 :
		CMD_LINE_MC
		CMD_LINE_MT
		CMD_LINE_SW
		CMD_LINE_DA
;

/*--------------------------------------------------------------------------*/
/*	コマンド(行)定義														*/
/*--------------------------------------------------------------------------*/
/*	位置情報(P)パターン														*/
CMD_LINE_POS :
	/*	位置情報(P)正常系													*/
	CMD_TOKEN_P LT_DOUBLE LT_COMMA LT_DOUBLE LT_COMMA LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_POS");
		cmd_pos(cmd_line, $2, $4, $6);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	/*	位置情報(P)異常系														*/
	| CMD_TOKEN_P LT_POS_ERR LT_COMMA LT_POS_ERR LT_COMMA LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_POS");
		cmd_pos(cmd_line, GPS_ERROR_LATITUDE, GPS_ERROR_LONGITUDE, $6);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

/*	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*	アワメータ(H)パターン集約												*/
CMD_LINE_HOUR_METER :
	CMD_TOKEN_H LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_HOUR_METER");
		cmd_h(cmd_line, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

/*	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*	エリア内警報(A)パターン													*/
CMD_LINE_AREA_NAIGAI_A :
	CMD_TOKEN_A LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_AREA_NAIGAI_A");
		cmd_a(cmd_line, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

/*	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*	侵入警報(SC)パターン													*/
CMD_LINE_ALARM_SC :
	CMD_TOKEN_SC LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_ALARM_SC");
		cmd_sc(cmd_line, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

/*	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*	エリア外警報(SA)パターン												*/
CMD_LINE_ALARM_SA :
	CMD_TOKEN_SA LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_ALARM_SA");
		cmd_sa(cmd_line, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

/*	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*	バッテリーはずし警報(BT)パターン										*/
CMD_LINE_ALARM_BT :
	CMD_TOKEN_BT LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_ALARM_BT");
		cmd_bt(cmd_line, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;


/*	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*	エンジン状態(EG)パターン												*/
CMD_LINE_EG :
	CMD_TOKEN_EG LT_ON LT_RETURN
	{
		_CMD_START("CMD_LINE_EG");
		cmd_eg(cmd_line, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	|	CMD_TOKEN_EG LT_OFF LT_RETURN
	{
		_CMD_START("CMD_LINE_EG");
		cmd_eg(cmd_line, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

/*	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*	侵入警報設定(AMON)応答パターン集約										*/
CMD_LINE_AM_ON :
	CMD_TOKEN_AMON LT_INTVAL LT_OKNG LT_RETURN
	{
		_CMD_START("CMD_LINE_AM_ON");
		cmd_amon(cmd_line, $2, $3);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_AM_OF :
	CMD_TOKEN_AMOF LT_INTVAL LT_OKNG LT_RETURN
	{
		_CMD_START("CMD_LINE_AM_OF");
		cmd_amof(cmd_line, $2, $3);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_AM :
	CMD_TOKEN_AM LT_INTVAL LT_OKNG LT_RETURN
	{
		_CMD_START("CMD_LINE_AM");
		cmd_am(cmd_line, $2, $3);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

/*	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*	エリア設定(CL)応答パターン												*/
CMD_LINE_CL :
	/*	エリア設定(CL)(解除)応答											*/
	CMD_TOKEN_CL LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC  LT_OKNG LT_RETURN
	{
		_CMD_START("CMD_LINE_CL");
		cmd_cl(cmd_line, $2, $4, $6, $8, $9);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	/*	エリア設定(CL)応答													*/
	| CMD_TOKEN_CL LT_DOUBLE LT_COMMA LT_DOUBLE LT_COMMA LT_DOUBLE LT_COMMA LT_DOUBLE LT_OKNG LT_RETURN
	{
		_CMD_START("CMD_LINE_CL");
		cmd_cl(cmd_line, $2, $4, $6, $8, $9);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	/*	エリア設定(CL)(解除)応答(CR許容)									*/
	| CMD_TOKEN_CL LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_RETURN_2 LT_OKNG LT_RETURN
	{
		_CMD_START("CMD_LINE_CL(CR)");
		cmd_cl(cmd_line, $2, $4, $6, $8, $10);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	/*	エリア設定(CL)応答(CR許容)											*/
	| CMD_TOKEN_CL LT_DOUBLE LT_COMMA LT_DOUBLE LT_COMMA LT_DOUBLE LT_COMMA LT_DOUBLE LT_RETURN_2 LT_OKNG LT_RETURN
	{
		_CMD_START("CMD_LINE_CL(CR)");
		cmd_cl(cmd_line, $2, $4, $6, $8, $10);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	/*	エリア設定(CL)(解除)応答(LF許容)									*/
	| CMD_TOKEN_CL LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_RETURN LT_OKNG LT_RETURN
	{
		_CMD_START("CMD_LINE_CL(LF)");
		cmd_cl(cmd_line, $2, $4, $6, $8, $10);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	/*	エリア設定(CL)応答(LF許容)											*/
	| CMD_TOKEN_CL LT_DOUBLE LT_COMMA LT_DOUBLE LT_COMMA LT_DOUBLE LT_COMMA LT_DOUBLE LT_RETURN LT_OKNG LT_RETURN
	{
		_CMD_START("CMD_LINE_CL(LF)");
		cmd_cl(cmd_line, $2, $4, $6, $8, $10);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	/*	エリア設定(CL)(解除)応答(CRLF許容)									*/
	| CMD_TOKEN_CL LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_RETURN_2 LT_RETURN LT_OKNG LT_RETURN
	{
		_CMD_START("CMD_LINE_CL(CRLF)");
		cmd_cl(cmd_line, $2, $4, $6, $8, $11);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	/*	エリア設定(CL)応答(CRLF許容)											*/
	| CMD_TOKEN_CL LT_DOUBLE LT_COMMA LT_DOUBLE LT_COMMA LT_DOUBLE LT_COMMA LT_DOUBLE LT_RETURN_2 LT_RETURN LT_OKNG LT_RETURN
	{
		_CMD_START("CMD_LINE_CL(CRLF)");
		cmd_cl(cmd_line, $2, $4, $6, $8, $11);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	/*	エリア設定(CL)(解除)応答(LFCR許容)									*/
	| CMD_TOKEN_CL LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_RETURN LT_RETURN_2 LT_OKNG LT_RETURN
	{
		_CMD_START("CMD_LINE_CL(LFCR)");
		cmd_cl(cmd_line, $2, $4, $6, $8, $11);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	/*	エリア設定(CL)応答(LFCR許容)											*/
	| CMD_TOKEN_CL LT_DOUBLE LT_COMMA LT_DOUBLE LT_COMMA LT_DOUBLE LT_COMMA LT_DOUBLE LT_RETURN LT_RETURN_2 LT_OKNG LT_RETURN
	{
		_CMD_START("CMD_LINE_CL(LFCR)");
		cmd_cl(cmd_line, $2, $4, $6, $8, $11);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

/*	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*	通信停止(CM0)応答パターン												*/
CMD_LINE_CM0 :
	CMD_TOKEN_CM0 LT_OKNG LT_RETURN
	{
		_CMD_START("CMD_LINE_CM0");
		cmd_cm0(cmd_line, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

/*	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*	通信開始(CM1)応答パターン												*/
CMD_LINE_CM1 :
	CMD_TOKEN_CM1 LT_OKNG LT_RETURN
	{
		_CMD_START("CMD_LINE_CM1");
		cmd_cm1(cmd_line, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

/*	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*	電話番号通知パターン													*/
CMD_LINE_D0 :
	CMD_TOKEN_D0 LT_COMMA LT_TEXT_EX LT_RETURN
	{
		_CMD_START("CMD_LINE_D0");
		cmd_d0(cmd_line, $3);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

/*	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*	IPアドレス通知パターン													*/
CMD_LINE_D1 :
	CMD_TOKEN_D1 LT_COMMA LT_IP_ADDR LT_RETURN
	{
		_CMD_START("CMD_LINE_D1");
		cmd_d1(cmd_line, $3);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

/*	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*	西暦年通知パターン														*/
CMD_LINE_D2 :
	CMD_TOKEN_D2 LT_COMMA LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_D2");
		cmd_d2(cmd_line, $3);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

/*	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*	メカトロ有無通知パターン												*/
CMD_LINE_D3 :
	CMD_TOKEN_D3 LT_COMMA LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_D3");
		cmd_d3(cmd_line, $3);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

/*	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*	受信バイト数通知パターン												*/
CMD_LINE_M0 :
	CMD_TOKEN_M0 LT_COMMA LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_M0");
		cmd_m0(cmd_line, $3);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

/*	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*	送信バイト数通知パターン集約											*/
CMD_LINE_M1 :
	CMD_TOKEN_M1 LT_COMMA LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_M1");
		cmd_m1(cmd_line, $3);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

/*	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*	受信メール数通知パターン集約											*/
CMD_LINE_M2 :
	CMD_TOKEN_M2 LT_COMMA LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_M2");
		cmd_m2(cmd_line, $3);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

/*	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*	送信メール数通知パターン集約											*/
CMD_LINE_M3 :
	CMD_TOKEN_M3 LT_COMMA LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_M3");
		cmd_m3(cmd_line, $3);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

/*	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*	リトライ回数通知パターン集約											*/
CMD_LINE_M4 :
	CMD_TOKEN_M4 LT_COMMA LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_M4");
		cmd_m4(cmd_line, $3);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

/*	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*	(予備-M5)											*/
CMD_LINE_M5 :
	CMD_TOKEN_M5 LT_COMMA LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_M5");
		cmd_m5(cmd_line, $3);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

/*	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*	(予備-M6)											*/
CMD_LINE_M6 :
	CMD_TOKEN_M6 LT_COMMA LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_M6");
		cmd_m6(cmd_line, $3);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

/*	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*	(予備-M7)											*/
CMD_LINE_M7 :
	CMD_TOKEN_M7 LT_COMMA LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_M7");
		cmd_m7(cmd_line, $3);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

/*	- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*	(予備-M8)											*/
CMD_LINE_M8 :
	CMD_TOKEN_M8 LT_COMMA LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_M8");
		cmd_m8(cmd_line, $3);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_EGN_T :
	CMD_TOKEN_T LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_EGN_T");
		/*cmd_CMD_LINE_EGN_T(cmd_line, $2);*/
		cmd_t(cmd_line, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_EGN_P :
	CMD_TOKEN_P LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_EGN_P");
		cmd_p(cmd_line, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_IDOL_I :
	CMD_TOKEN_I LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_IDOL_I");
		cmd_i(cmd_line, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_RUN_R :
	CMD_TOKEN_R LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_RUN_R");
		cmd_r(cmd_line, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_HIREACH_C :
	CMD_TOKEN_C LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_HIREACH_C");
		cmd_c(cmd_line, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_NIBURA_N :
	CMD_TOKEN_N LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_NIBURA_N");
		cmd_n(cmd_line, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_FUEL_F :
	CMD_TOKEN_F LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_FUEL_F");
		cmd_f(cmd_line, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_ENGN_W :
	CMD_TOKEN_W LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_ENGN_W");
		cmd_w(cmd_line, $2, $4, $6, $8);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_PUMP_U :
	CMD_TOKEN_U LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_PUMP_U");
		cmd_u(cmd_line, $2, $4, $6, $8);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_KADO_J :
	CMD_TOKEN_J LT_RETURN
	{
		/* 処理なし(値省略を許可) */
		_CMD_START("CMD_LINE_KADO_J(No Values)");
		next_cmd();
	}
	| CMD_TOKEN_J LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_KADO_J");
		cmd_j(cmd_line, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_ENGN_OIL_EC :
	CMD_TOKEN_EC LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_ENGN_OIL_EC");
		cmd_ec(cmd_line, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_FUEL_FILTER_FC :
	CMD_TOKEN_FC LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_FUEL_FILTER_FC");
		cmd_fc(cmd_line, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_SADO_FILTER_HC :
	CMD_TOKEN_HC LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_SADO_FILTER_HC");
		cmd_hc(cmd_line, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_SADO_CHANGE_LC :
	CMD_TOKEN_LC LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_SADO_CHANGE_LC");
		cmd_lc(cmd_line, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_OVER_OV :
	CMD_TOKEN_OV LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_OVER_OV");
		cmd_ov(cmd_line, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_FUEL_ONDO_FT :
	CMD_TOKEN_FT LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_FUEL_ONDO_FT");
		cmd_ft(cmd_line, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_FUEL_STATUS_FS :
	CMD_TOKEN_FS LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_FUEL_STATUS_FS");
		cmd_fs(cmd_line, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_AMNG :
	CMD_TOKEN_AM LT_OKNG LT_RETURN
	{
		_CMD_START("CMD_LINE_AMNG");
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_HSOK :
	CMD_TOKEN_HS LT_INTVAL LT_OKNG LT_RETURN
	{
		_CMD_START("CMD_LINE_HSOK");
		cmd_hs(cmd_line, $2, $3);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_HSNG :
	CMD_TOKEN_HS LT_OKNG LT_RETURN
	{
		_CMD_START("CMD_LINE_HSNG");
		cmd_hs(cmd_line, "", $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_HEOK :
	CMD_TOKEN_HE LT_INTVAL LT_OKNG LT_RETURN
	{
		_CMD_START("CMD_LINE_HEOK");
		cmd_he(cmd_line, $2, $3);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_HENG :
	CMD_TOKEN_HE LT_OKNG LT_RETURN
	{
		_CMD_START("CMD_LINE_HENG");
		cmd_he(cmd_line, "", $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_HFOK :
	CMD_TOKEN_HF LT_INTVAL LT_OKNG LT_RETURN
	{
		_CMD_START("CMD_LINE_HFOK");
		cmd_hf(cmd_line, $2, $3);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_HFNG :
	CMD_TOKEN_HF LT_OKNG LT_RETURN
	{
		_CMD_START("CMD_LINE_HFNG");
		cmd_hf(cmd_line, "", $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_HHOK :
	CMD_TOKEN_HH LT_INTVAL LT_OKNG LT_RETURN
	{
		_CMD_START("CMD_LINE_HHOK");
		cmd_hh(cmd_line, $2, $3);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_HHNG :
	CMD_TOKEN_HH LT_OKNG LT_RETURN
	{
		_CMD_START("CMD_LINE_HHNG");
		cmd_hh(cmd_line, "", $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_HLOK :
	CMD_TOKEN_HL LT_INTVAL LT_OKNG LT_RETURN
	{
		_CMD_START("CMD_LINE_HLOK");
		cmd_hl(cmd_line, $2, $3);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_HLNG :
	CMD_TOKEN_HL LT_OKNG LT_RETURN
	{
		_CMD_START("CMD_LINE_HLNG");
		cmd_hl(cmd_line, "", $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_AH :
	CMD_TOKEN_AH LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_RETURN
	{
		_CMD_START("CMD_LINE_AH");
		cmd_ah(cmd_line, $2, $4, $6, $8, $10, $12, $14, $16, $18, $20, $22, $24, $26, $28, $30, $32);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_PN :
	CMD_TOKEN_PN LT_TEXT_EX LT_RETURN
	{
		_CMD_START("CMD_LINE_PN");
		cmd_pn(cmd_line, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_VR :
	CMD_TOKEN_VR LT_TEXT_EX LT_RETURN
	{
		_CMD_START("CMD_LINE_VR");
		cmd_vr(cmd_line, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_XX :
	CMD_TOKEN_XX LT_INTVAL LT_COMMA LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_XX");
		cmd_xx(cmd_line, $1, $2, $4);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	|CMD_TOKEN_XX LT_TEXT LT_COMMA LT_INTVAL LT_RETURN
	{
		char *_param2 = 0x00;
		
		if($2[0]=='*'){
			_param2 = "0";
		}else{
			_param2 = $2;
		}
		
		_CMD_START("CMD_LINE_XX");
		cmd_xx(cmd_line, $1, _param2, $4);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_XX_V7 :
	CMD_TOKEN_XX LT_INTVAL LT_COMMA LT_TEXT_EX LT_COMMA LT_INT10 LT_RETURN
	{
		_CMD_START("CMD_LINE_XX_V7");
		cmd_xx_v7(cmd_line, $1, $2, $4, $6);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	|CMD_TOKEN_XX LT_TEXT LT_COMMA LT_TEXT_EX LT_COMMA LT_INT10 LT_RETURN
	{
		char *_param2 = 0x00;
		
		if($2[0]=='*'){
			_param2 = "0";
		}else{
			_param2 = $2;
		}
		
		_CMD_START("CMD_LINE_XX_V7");
		cmd_xx_v7(cmd_line, $1, _param2, $4, $6);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	|CMD_TOKEN_XX LT_INTVAL LT_COMMA LT_TEXT_EX LT_COMMA LT_INT10 LT_COMMA LT_TEXT_EX LT_RETURN
	{
		_CMD_START("CMD_LINE_XX_V7");
		cmd_xx_v7_eg(cmd_line, $1, $2, $4, $6, $8);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}   
;

CMD_LINE_SD_1 :
	CMD_TOKEN_SD_1 LT_INT2 LT_COMMA LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_SD_1");
		cmd_sd1(cmd_line, $2, $4);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_SD_2 :
	CMD_TOKEN_SD_2 LT_TEXT_EX LT_RETURN
	{
		_CMD_START("CMD_LINE_SD_2");
		cmd_sd2(cmd_line, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_SD_3 :
	CMD_TOKEN_SD_1 LT_INT2 LT_OKNG LT_RETURN
	{
		_CMD_START("CMD_LINE_SD_3");
		cmd_sd3(cmd_line, $2, $3);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_NENPI :
	CMD_TOKEN_NENPI LT_INTVAL LT_COMMA LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_NENPI");
		cmd_np(cmd_line, $2, $4);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;


CMD_LINE_V :
	CMD_TOKEN_V LT_TEXT_EX LT_RETURN
	{
		_CMD_START("CMD_LINE_V");
		cmd_vr(cmd_line, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_EA :
	CMD_TOKEN_EA LT_TEXT_EX LT_RETURN
	{
		_CMD_START("CMD_LINE_EA");
		cmd_ea(cmd_line, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_PA :
	CMD_TOKEN_PA LT_TEXT_EX LT_RETURN
	{
		_CMD_START("CMD_LINE_PA");
		cmd_pa(cmd_line, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_PB :
	CMD_TOKEN_PB LT_TEXT_EX LT_RETURN
	{
		_CMD_START("CMD_LINE_PB");
		cmd_pb(cmd_line, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_PC :
	CMD_TOKEN_PC LT_TEXT_EX LT_RETURN
	{
		_CMD_START("CMD_LINE_PC");
		cmd_pc(cmd_line, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_UA :
	CMD_TOKEN_UA LT_TEXT_EX LT_RETURN
	{
		_CMD_START("CMD_LINE_UA");
		cmd_ua(cmd_line, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_UB :
	CMD_TOKEN_UB LT_TEXT_EX LT_RETURN
	{
		_CMD_START("CMD_LINE_UB");
		cmd_ub(cmd_line, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_SW :
	CMD_TOKEN_SW LT_TEXT_EX LT_RETURN
	{
		_CMD_START("CMD_LINE_SW");
		cmd_sw(cmd_line, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_ST :
	CMD_TOKEN_ST LT_TEXT_EX LT_RETURN
	{
		_CMD_START("CMD_LINE_ST");
		cmd_st(cmd_line, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_MC :
	CMD_TOKEN_MC LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_MC");
		cmd_mc(cmd_line, $2 , $4 , $6 );
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	|CMD_TOKEN_MC LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_MC");
		cmd_mc(cmd_line, $2 , $4 , $6 );
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_MT :
	CMD_TOKEN_MT LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_MT");
		cmd_mt(cmd_line, $2 , $4 , $6 );
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	|CMD_TOKEN_MT LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_MT");
		cmd_mt(cmd_line, $2 , $4 , $6 );
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_DA :
	CMD_TOKEN_DA LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_DA");
		cmd_da(cmd_line, $1, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_SL :
	CMD_TOKEN_SL LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_SL");
		cmd_sl(cmd_line, $2 );
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_TD :
	CMD_TOKEN_TD LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_TD");
		cmd_td(cmd_line, $2, "");
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_RES_TD :
	CMD_TOKEN_TD LT_INTVAL LT_OKNG LT_RETURN
	{
		_CMD_START("CMD_LINE_RES_TD-1");
		cmd_td(cmd_line, $2 , $3);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	|CMD_TOKEN_TD LT_OKNG LT_RETURN
	{
		_CMD_START("CMD_LINE_RES_TD-2");
		cmd_td(cmd_line, "" , $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_AE :
	CMD_TOKEN_AE LT_INTVAL LT_COMMA LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_AE");
		cmd_ae(cmd_line , $2 , $4);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_AR :
	CMD_TOKEN_AR LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_AR(1-25)");
		cmd_ar(cmd_line , $2 , $4 , $6, $8, $10, $12, $14, $16, $18, $20, $22, $24, $26, $28, $30, $32, $34, $36, $38, $40, $42, $44, $46, $48, $50 );
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	|CMD_TOKEN_AR LT_INTVAL LT_COMMA LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_AR(0)");
		cmd_ar(cmd_line , $2 , $4 , "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" );
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_X1 :
	CMD_TOKEN_X1 LT_TEXT_EX LT_RETURN
	{
		_CMD_START("CMD_LINE_X1");
		cmd_x1(cmd_line, $1,  1, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	|CMD_TOKEN_X1 LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_RETURN
	{
		_CMD_START("CMD_LINE_X1");
		cmd_x1(cmd_line, $1,  4, $2, $4, $6, $8);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	|CMD_TOKEN_X1 LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_RETURN
	{
		_CMD_START("CMD_LINE_X1");
		cmd_x1(cmd_line, $1,  3, $2, $4, $6);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	|CMD_TOKEN_X1 LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_RETURN
	{
		_CMD_START("CMD_LINE_X1");
		cmd_x1(cmd_line, $1,  5, $2, $4, $6, $8, $10);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	|CMD_TOKEN_X1 LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_RETURN
	{
		_CMD_START("CMD_LINE_X1");
		cmd_x1(cmd_line, $1, 12, $2, $4, $6, $8, $10, $12, $14, $16, $18, $20, $22, $24);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	|CMD_TOKEN_X1 LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_RETURN
	{
		_CMD_START("CMD_LINE_X1");
		cmd_x1(cmd_line, $1, 13, $2, $4, $6, $8, $10, $12, $14, $16, $18, $20, $22, $24, $26);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	|CMD_TOKEN_X1 LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_RETURN
	{
		_CMD_START("CMD_LINE_X1");
		cmd_x1(cmd_line, $1, 26, $2, $4, $6, $8, $10, $12, $14, $16, $18, $20, $22, $24, $26, $28, $30, $32, $34, $36, $38, $40, $42, $44, $46, $48, $50, $52);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	|CMD_TOKEN_X1 LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_RETURN
	{
		_CMD_START("CMD_LINE_X1");
		cmd_x1(cmd_line, $1, 2, $2, $4);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	|CMD_TOKEN_X1 LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_RETURN
	{
		_CMD_START("CMD_LINE_X1");
		cmd_x1(cmd_line, $1, 17, $2, $4, $6, $8, $10, $12, $14, $16, $18, $20, $22, $24, $26, $28, $30, $32, $34);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	|CMD_TOKEN_X1 LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_RETURN
	{
		_CMD_START("CMD_LINE_X1");
		cmd_x1(cmd_line, $1, 11, $2, $4, $6, $8, $10, $12, $14, $16, $18, $20, $22);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	|CMD_TOKEN_X1 LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX  LT_RETURN
	{
		_CMD_START("CMD_LINE_X1");
		cmd_x1(cmd_line, $1, 6, $2, $4, $6, $8, $10, $12);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	|CMD_TOKEN_X1 LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_RETURN
	{
		_CMD_START("CMD_LINE_X1");
		cmd_x1(cmd_line, $1, 8, $2, $4, $6, $8, $10, $12, $14, $16);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_HA :
	CMD_TOKEN_HA LT_TEXT_EX LT_RETURN
	{
		_CMD_START("CMD_LINE_HA");
		cmd_ha(cmd_line, $1, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_LK :
	CMD_TOKEN_LK LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_LK");
		cmd_lk(cmd_line, $1, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_YD :
	CMD_TOKEN_YD LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_YD");
		cmd_yd(cmd_line, $1, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_OT :
	CMD_TOKEN_OT LT_NUMERIC LT_RETURN
	{
		_CMD_START("CMD_LINE_OT");
		cmd_ot(cmd_line, $1, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_M :
	CMD_TOKEN_M LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_OT");
		cmd_m(cmd_line, $1, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_JH :
	CMD_TOKEN_JH LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_JH");
		cmd_jh(cmd_line, $1, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_JS :
	CMD_TOKEN_JS LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_JS");
		cmd_js(cmd_line, $1, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_JE :
	CMD_TOKEN_JE LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_JE");
		cmd_je(cmd_line, $1, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_AB :
	CMD_TOKEN_AB LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_AB");
		cmd_ab(cmd_line, $1, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_SS :
	CMD_TOKEN_SS LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_SS");
	#ifdef DEBUG
	printf("[%s][Line:%04d][%s]\n",__FUNCTION__,__LINE__,cmd_line);
	printf("[%s][Line:%04d][%s]\n",__FUNCTION__,__LINE__,$1);
	printf("[%s][Line:%04d][%s]\n",__FUNCTION__,__LINE__,$2);
	#endif

		cmd_ss(cmd_line, $1, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_SR :
	CMD_TOKEN_SR LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_SR");
		cmd_sr(cmd_line, $1, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_SG :
	CMD_TOKEN_SG LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_SG");
		cmd_sg(cmd_line, $1, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_SU :
	CMD_TOKEN_SU LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_SU");
		cmd_su(cmd_line, $1, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_RES_REMOTE_DL :
	CMD_TOKEN_DG LT_OKNG LT_COMMA LT_TEXT_EX LT_COMMA LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_DG");
		cmd_res_remote_dl( cmd_line, $1 , $2 , $4 , $6 );
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	|CMD_TOKEN_DU LT_OKNG LT_COMMA LT_TEXT_EX LT_COMMA LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_DU");
		cmd_res_remote_dl( cmd_line, $1 , $2 , $4 , $6 );
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	|CMD_TOKEN_DC LT_OKNG LT_COMMA LT_TEXT_EX LT_COMMA LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_DC");
		cmd_res_remote_dl( cmd_line, $1 , $2 , $4 , $6 );
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	|CMD_TOKEN_DR LT_OKNG LT_COMMA LT_TEXT_EX LT_COMMA LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_DR");
		cmd_res_remote_dl( cmd_line, $1 , $2 , $4 , $6 );
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	|CMD_TOKEN_DR LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_DR");
		cmd_res_remote_dl( cmd_line, $1 , $2 , $4 , $6 );
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_ASTRSK1 :
	CMD_TOKEN_ASTRSK1 LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_RETURN
	{
		_CMD_START("CMD_LINE_ASTRSK1(5)");
		cmd_astrsk1(cmd_line, 5 , $2, $4, $6, $8, $10);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	|CMD_TOKEN_ASTRSK1 LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_RETURN
	{
		_CMD_START("CMD_LINE_ASTRSK1(4)");
		cmd_astrsk1(cmd_line, 4 , $2, $4, $6, $8);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	|CMD_TOKEN_ASTRSK1 LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_RETURN
	{
		_CMD_START("CMD_LINE_ASTRSK1(3)");
		cmd_astrsk1(cmd_line, 3 , $2, $4, $6);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	|CMD_TOKEN_ASTRSK1 LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_RETURN
	{
		_CMD_START("CMD_LINE_ASTRSK1(2)");
		cmd_astrsk1(cmd_line, 2 , $2, $4);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	|CMD_TOKEN_ASTRSK1 LT_TEXT_EX LT_RETURN
	{
		_CMD_START("CMD_LINE_ASTRSK1(1)");
		cmd_astrsk1(cmd_line, 1 ,$2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_ASTRSK2 :
	CMD_TOKEN_ASTRSK2 LT_TEXT LT_RETURN
	{
		_CMD_START("CMD_LINE_ASTRSK2");
		cmd_astrsk2(cmd_line, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;


CMD_LINE_NUMSIGN :
	CMD_TOKEN_NUMSIGN LT_TEXT_EX LT_RETURN
	{
		_CMD_START("CMD_LINE_NUMSIGN");
		cmd_numsign(cmd_line, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;


CMD_LINE_HD :
	CMD_TOKEN_HD LT_OKNG LT_RETURN
	{
		_CMD_START("CMD_LINE_HD");
		cmd_fd(cmd_line, $1, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;


CMD_LINE_HP :
	CMD_TOKEN_HP LT_TEXT_EX LT_RETURN
	{
		_CMD_START("CMD_LINE_HP");
		cmd_fd(cmd_line, $1, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;


CMD_LINE_HQ :
	CMD_TOKEN_HQ LT_TEXT_EX LT_RETURN
	{
		_CMD_START("CMD_LINE_HQ");
		cmd_fd(cmd_line, $1, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_FR :
	CMD_TOKEN_FR LT_TEXT_EX LT_RETURN
	{
		_CMD_START("CMD_LINE_FR");
		cmd_fd(cmd_line, $1, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_FD :
	CMD_TOKEN_FD LT_TEXT_EX LT_RETURN
	{
		_CMD_START("CMD_LINE_FD");
		cmd_fd(cmd_line, $1, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;


CMD_LINE_FQ :
	CMD_TOKEN_FQ LT_TEXT_EX LT_RETURN
	{
		_CMD_START("CMD_LINE_FQ");
		cmd_fd(cmd_line, $1, $2);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_RR :
    CMD_TOKEN_RR LT_INTVAL LT_COMMA LT_TEXT_EX LT_RETURN
	{
		_CMD_START("CMD_LINE_RR(0)");
		cmd_rr(cmd_line , $2, $4, "", "", "", "", "", "", "", "", "" );
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	|CMD_TOKEN_RR LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_RR(1)");
		cmd_rr(cmd_line , $2, $4, $6, $8, $10, $12, $14, $16, $18, $20, $22 );
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	|CMD_TOKEN_RR LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_RR(2)");
		cmd_rr(cmd_line , $2, $4, $6, $8, $10, $12, $14, $16, $18, "", "" );
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_SSID :
	CMD_TOKEN_SSID LT_OKNG LT_COMMA LT_INTVAL LT_RETURN
	{
		_CMD_START("CMD_LINE_SSID");
		cmd_ssid(cmd_line, $2, $4);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_LKOK :
	CMD_TOKEN_LK LT_INTVAL LT_OKNG LT_RETURN
	{
		_CMD_START("CMD_LINE_LKOK");
		cmd_lkok(cmd_line, $1, $2, $3);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_VE :
	CMD_TOKEN_VE LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_RETURN
	{
		_CMD_START("CMD_LINE_VE");
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$1",$1);
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$2",$2);
		cmd_x1(cmd_line, $1,  4, $2, $4, $6, $8);

		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_TC :
	CMD_TOKEN_TC LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_RETURN
	{
		_CMD_START("CMD_LINE_TC");
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$1",$1);
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$2",$2);
		cmd_x1(cmd_line, $1, 12, $2, $4, $6, $8, $10, $12, $14, $16, $18, $20,"55535","55535");
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	|CMD_TOKEN_TC LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_RETURN
	{
		_CMD_START("CMD_LINE_TC");
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$1",$1);
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$2",$2);
		cmd_x1(cmd_line, $1, 12, $2, $4, $6, $8, $10, $12, $14, $16, $18, $20, $22, $24);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

CMD_LINE_KL :
	CMD_TOKEN_KL LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_DOUBLE LT_COMMA LT_TEXT_EX LT_COMMA LT_DOUBLE LT_COMMA LT_DOUBLE LT_RETURN
	{
		_CMD_START("CMD_LINE_KL");
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$1",$1);
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$3",$3);
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$5",$5);
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$7",$7);
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$9",$9);
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$11",$11);
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$13",$13);
		cmd_kl(cmd_line, $3, $5, $7, $9, $11, $13);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	|CMD_TOKEN_KL LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_INTVAL LT_COMMA LT_TEXT_EX LT_COMMA LT_DOUBLE LT_COMMA LT_DOUBLE LT_RETURN
	{
		_CMD_START("CMD_LINE_KL");
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$1",$1);
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$3",$3);
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$5",$5);
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$7",$7);
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$9",$9);
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$11",$11);
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$13",$13);
		cmd_kl(cmd_line, $3, $5, $7, $9, $11, $13);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	|CMD_TOKEN_KL LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_DOUBLE LT_COMMA LT_DOUBLE LT_RETURN
	{
		_CMD_START("CMD_LINE_KL");
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$1",$1);
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$3",$3);
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$5",$5);
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$7",$7);
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$9",$9);
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$11",$11);
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$13",$13);
		cmd_kl(cmd_line, $3, $5, $7, $9, $11, $13);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
	|CMD_TOKEN_KL LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_DOUBLE LT_COMMA LT_TEXT_EX LT_COMMA LT_POS_ERR LT_COMMA LT_POS_ERR LT_RETURN
	{
		_CMD_START("CMD_LINE_KL");
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$1",$1);
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$3",$3);
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$5",$5);
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$7",$7);
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$9",$9);
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$11",$11);
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$13",$13);
		cmd_kl(cmd_line, $3, $5, $7, $9, $11, $13);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}	
	|CMD_TOKEN_KL LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_INTVAL LT_COMMA LT_TEXT_EX LT_COMMA LT_POS_ERR LT_COMMA LT_POS_ERR LT_RETURN
	{
		_CMD_START("CMD_LINE_KL");
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$1",$1);
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$3",$3);
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$5",$5);
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$7",$7);
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$9",$9);
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$11",$11);
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$13",$13);
		cmd_kl(cmd_line, $3, $5, $7, $9, $11, $13);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}	
	|CMD_TOKEN_KL LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_POS_ERR LT_COMMA LT_POS_ERR LT_RETURN
	{
		_CMD_START("CMD_LINE_KL");
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$1",$1);
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$3",$3);
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$5",$5);
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$7",$7);
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$9",$9);
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$11",$11);
		printf("[%s][Line:%04d]%s = %s\n",__FUNCTION__,__LINE__,"$13",$13);
		cmd_kl(cmd_line, $3, $5, $7, $9, $11, $13);
		/*	コマンド１行解析終了(次のコマンド解析モードへ)	*/
		next_cmd();
	}
;

/*--------------------------------------------------------------------------*/
/*	トークンの同一視																*/
/*--------------------------------------------------------------------------*/

LT_TEXT_EX :
	LT_TEXT
	|LT_NUMERIC
	|LT_OKNG
;

LT_NUMERIC :
	LT_INTVAL
	|LT_HEX
;

LT_INTVAL :
	LT_INTEGER
	|LT_INT2
	|LT_INT10
;

%%

int _MAIL(){
	int ret = -1;
	
	/*	解析モードをINITIALに設定する	*/
	setInitial_mode();
	yyclearin;

	return 0;
}

int _MAIL_HEADER(){
	
	#ifdef DEBUG
	printf("[%s][Line:%04d](...mail head end,next...BODY...)\n",__FUNCTION__,__LINE__);
	#endif
	
	return 0;
}

int _MLTYPE_ONLY_POS(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_ONLY_POS);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"");
	return 0;
}

int _MLTYPE_DAILY_DAYTIME(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_BATCH_DAYTIME);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"L");
	return 0;
}

int _MLTYPE_DAILY_NIGHT_OPE(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_BATCH_NIGHT_OPE);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"Y");
	return 0;
}

int _MLTYPE_DAILY_NIGHT_NON_OPE(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_BATCH_NIGHT_NOPE);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"Y");
	return 0;
}

int _MLTYPE_DAILY_NIGHT_EXCEPTION(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_BATCH_NIGHT_EXP);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"Y");
	return 0;
}

int _MLTYPE_RESPONSE_RT(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_RT);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"RT");
	return 0;
}

int _MLTYPE_ALARM_SC(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_SC);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"T");
	return 0;
}

int _MLTYPE_AMNG(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_AM);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"AM");
	return 0;
}

int _MLTYPE_HSOK(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_HS);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"HS");
	return 0;
}

int _MLTYPE_HSNG(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_HS);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"HS");
	return 0;
}

int _MLTYPE_HEOK(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_HE);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"HE");
	return 0;
}

int _MLTYPE_HENG(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_HE);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"HE");
	return 0;
}

int _MLTYPE_HFOK(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_HF);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"HF");
	return 0;
}

int _MLTYPE_HFNG(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_HF);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"HF");
	return 0;
}

int _MLTYPE_HHOK(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_HH);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"HH");
	return 0;
}

int _MLTYPE_HHNG(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_HH);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"HH");
	return 0;
}

int _MLTYPE_HLOK(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_HL);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"HL");
	return 0;
}

int _MLTYPE_HLNG(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_HL);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"HL");
	return 0;
}

int _MLTYPE_RESPONSE_AC(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_AH);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"AC");
	return 0;
}

int _MLTYPE_ALARM_SA(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_SA);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"T");
	return 0;
}

int _MLTYPE_ALARM_BT(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_BT);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"T");
	return 0;
}

int _MLTYPE_RESPONSE_AM(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_AM);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"AM");
	return 0;
}

int _MLTYPE_RESPONSE_CL(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_CL);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"CL");
	return 0;
}

int _MLTYPE_RESPONSE_CM0(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_CM0);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"CM0");
	return 0;
}

int _MLTYPE_RESPONSE_CM1(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_CM1);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"CM1");
	return 0;
}

int _MLTYPE_RESPONSE_CT0(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_CT0);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"CT0");
	return 0;
}

int _MLTYPE_RESPONSE_CT1(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_CT1);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"CT1");
	return 0;
}

int _MLTYPE_XX(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_XX);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"T");
	return 0;
}

int _MLTYPE_SD(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_SD);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"SD");
	return 0;
}

int _MLTYPE_RM(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_RM);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"RM");
	return 0;
}

int _MLTYPE_XX_V7(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_XX_V7);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"T");
	return 0;
}

int _MLTYPE_TD(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_TD);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"TD");
	return 0;
}

int _MLTYPE_DAILY_OPE(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_BATCH_OPE);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"Y1");
	return 0;
}

int _MLTYPE_DAILY_NOPE(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_BATCH_NOPE);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"Y2");
	return 0;
}

int _MLTYPE_ALARM_SS(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_SS);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"T");
	return 0;
}

int _MLTYPE_ALARM_SR(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_SR);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"T");
	return 0;
}

int _MLTYPE_ALARM_SG(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_SG);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"T");
	return 0;
}

int _MLTYPE_ALARM_SU(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_SU);
/*	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"T"); */
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"SU");
	return 0;
}
/*
int _MLTYPE_ALARM_HD(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_HD);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"HD");
	return 0;
}

int _MLTYPE_ALARM_HQ(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_HQ);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"HQ");
	return 0;
}

int _MLTYPE_ALARM_HP(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_HP);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"HP");
	return 0;
}
*/

int _MLTYPE_RES_REMOTE_DL(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_DG);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"DG");
	return 0;
}


int _MLTYPE_XXXX(int type){
	_MLTYPE_START(__FUNCTION__);
	#ifdef DEBUG
	printf("[%s][Line:%04d][%d]\n",__FUNCTION__,__LINE__,type);
	printf("\n");
	#endif
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_XXXX);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"9");
	return 0;
}

int _MLTYPE_ASTRSK(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_HANYO);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"**");
	return 0;
}

int _MLTYPE_FDFR(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_FDFR);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"FD");
	return 0;
}

int _MLTYPE_HDHQHP(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_HDHQHP);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"HD");
	return 0;
}

int _MLTYPE_LKOK(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_LKOK);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"LK");
	return 0;
}

int _MLTYPE_AE(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_AE);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"AE");
	return 0;
}

int _MLTYPE_AR(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_AR);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"AR");
	return 0;
}

int _MLTYPE_RR(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_RR);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"RR");
	return 0;
}

int _MLTYPE_SSID(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_SSID);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"SID");
	return 0;
}

int _MLTYPE_KL(){
	_MLTYPE_START(__FUNCTION__);
	strcpy(G_CMD_COM_PARAM.mail_type,MTYP_KL);
	strcpy(G_CMD_COM_PARAM.mail_type_forlog,"KL");
	return 0;
}

int _MLTYPE_START(char *s){
	printf("[%s][Line:%04d](^-^)%s\n",__FUNCTION__,__LINE__,s);
	printf("\n");
	
	return 0;
}

int _CMD_START(char *s){
	#ifdef DEBUG
	printf("[%s][Line:%04d](+_+)%s\n",__FUNCTION__,__LINE__,s);
	#endif
	
	return 0;
}

/* ============================================================================== */

int _eof(char* p){
	#ifdef DEBUG
	printf("[%s][Line:%04d]*************EOF*************\n",__FUNCTION__,__LINE__);
	#endif
	yyclearin;
	setInitial_mode();
	return 0;
}

yyerror (s)  /* エラーが起きるとyyparseから呼び出される */
     char *s;
{
	#ifdef DEBUG
	printf("[%s][Line:%04d]*************yyerror*************\n",__FUNCTION__,__LINE__);
	printf("[%s][Line:%04d]%s\n",__FUNCTION__,__LINE__,s);
	printf("[%s][Line:%04d]*********************************\n",__FUNCTION__,__LINE__);
	#endif
	
	yyclearin;
	setInitial_mode();
}
