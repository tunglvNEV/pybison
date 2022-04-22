#!/usr/bin/env python

"""
PyBison file automatically generated from grammar file itsh.y
You can edit this module, or import it and subclass the Parser class
"""

import sys

from bison import BisonParser, BisonNode, BisonSyntaxError

bisonFile = 'itsh.y'  # original bison file
lexFile = 'itsh.l'    # original flex file


class Parser(BisonParser):
    """
    bison Parser class generated automatically by bison2py from the
    grammar file "itsh.y" and lex file "itsh.l"

    You may (and probably should) edit the methods in this class.
    You can freely edit the rules (in the method docstrings), the
    tokens list, the start symbol, and the precedences.

    Each time this class is instantiated, a hashing technique in the
    base class detects if you have altered any of the rules. If any
    changes are detected, a new dynamic lib for the parser engine
    will be generated automatically.
    """

    # -------------------------------------------------
    # Default class to use for creating new parse nodes
    # -------------------------------------------------
    defaultNodeClass = BisonNode

    # --------------------------------------------
    # basename of binary parser engine dynamic lib
    # --------------------------------------------
    bisonEngineLibName = 'itsh-engine'

    # ----------------------------------------------------------------
    # lexer tokens - these must match those in your lex script (below)
    # ----------------------------------------------------------------
    tokens = ['LT_DOUBLE', 'LT_COMMA', 'LT_ON', 'LT_OFF', 'LT_OKNG', 'LT_POS_ERR', 'LT_IP_ADDR', 'LT_TEXT', 'LT_HEX', 'LT_INT2', 'LT_INT10', 'LT_INTEGER', 'CMD_TOKEN_H', 'CMD_TOKEN_SC', 'CMD_TOKEN_SA', 'CMD_TOKEN_BT', 'CMD_TOKEN_A', 'CMD_TOKEN_EG', 'CMD_TOKEN_AM', 'CMD_TOKEN_AMON', 'CMD_TOKEN_AMOF', 'CMD_TOKEN_CL', 'CMD_TOKEN_CM0', 'CMD_TOKEN_CM1', 'CMD_TOKEN_D0', 'CMD_TOKEN_D1', 'CMD_TOKEN_D2', 'CMD_TOKEN_D3', 'CMD_TOKEN_M0', 'CMD_TOKEN_M1', 'CMD_TOKEN_M2', 'CMD_TOKEN_M3', 'CMD_TOKEN_M4', 'CMD_TOKEN_M5', 'CMD_TOKEN_M6', 'CMD_TOKEN_M7', 'CMD_TOKEN_M8', 'CMD_TOKEN_T', 'CMD_TOKEN_P', 'CMD_TOKEN_I', 'CMD_TOKEN_R', 'CMD_TOKEN_C', 'CMD_TOKEN_N', 'CMD_TOKEN_F', 'CMD_TOKEN_W', 'CMD_TOKEN_U', 'CMD_TOKEN_J', 'CMD_TOKEN_EC', 'CMD_TOKEN_FC', 'CMD_TOKEN_HC', 'CMD_TOKEN_LC', 'CMD_TOKEN_OV', 'CMD_TOKEN_FT', 'CMD_TOKEN_FS', 'CMD_TOKEN_HS', 'CMD_TOKEN_HE', 'CMD_TOKEN_HF', 'CMD_TOKEN_HH', 'CMD_TOKEN_HL', 'CMD_TOKEN_AH', 'CMD_TOKEN_PN', 'CMD_TOKEN_VR', 'CMD_TOKEN_XX', 'CMD_TOKEN_SD_1', 'CMD_TOKEN_SD_2', 'CMD_TOKEN_NENPI', 'CMD_TOKEN_V', 'CMD_TOKEN_EA', 'CMD_TOKEN_PA', 'CMD_TOKEN_PB', 'CMD_TOKEN_PC', 'CMD_TOKEN_UA', 'CMD_TOKEN_UB', 'CMD_TOKEN_SW', 'CMD_TOKEN_ST', 'CMD_TOKEN_MC', 'CMD_TOKEN_MT', 'CMD_TOKEN_DA', 'CMD_TOKEN_SL', 'CMD_TOKEN_TD', 'CMD_TOKEN_AE', 'CMD_TOKEN_AR', 'CMD_TOKEN_X1', 'TOKEN_ERROR', 'LT_HEADER_ONE_LINE', 'LT_RETURN_HEADER', 'LT_RETURN', 'LT_RETURN_2', 'CMD_TOKEN_HA', 'CMD_TOKEN_LK', 'CMD_TOKEN_YD', 'CMD_TOKEN_OT', 'CMD_TOKEN_M', 'CMD_TOKEN_JH', 'CMD_TOKEN_JS', 'CMD_TOKEN_JE', 'CMD_TOKEN_AB', 'CMD_TOKEN_SS', 'CMD_TOKEN_SR', 'CMD_TOKEN_SG', 'CMD_TOKEN_SU', 'CMD_TOKEN_HD', 'CMD_TOKEN_HQ', 'CMD_TOKEN_HP', 'CMD_TOKEN_DG', 'CMD_TOKEN_DU', 'CMD_TOKEN_DC', 'CMD_TOKEN_DR', 'CMD_TOKEN_ASTRSK1', 'CMD_TOKEN_ASTRSK2', 'CMD_TOKEN_NUMSIGN', 'CMD_TOKEN_FD', 'CMD_TOKEN_FR', 'CMD_TOKEN_FQ', 'CMD_TOKEN_VE', 'CMD_TOKEN_TC', 'CMD_TOKEN_RR', 'CMD_TOKEN_SSID', 'CMD_TOKEN_KL']

    # ------------------------------
    # precedences
    # ------------------------------
    precedences = (
        )

    # ---------------------------------------------------------------
    # Declare the start target here (by name)
    # ---------------------------------------------------------------
    start = 'MAIL'

    # ---------------------------------------------------------------
    # These methods are the python handlers for the bison targets.
    # (which get called by the bison code each time the corresponding
    # parse target is unambiguously reached)
    #
    # WARNING - don't touch the method docstrings unless you know what
    # you are doing - they are in bison rule syntax, and are passed
    # verbatim to bison to build the parser engine library.
    # ---------------------------------------------------------------

    def on_MAIL(self, target, option, names, values):
        """
        MAIL
            : MAIL_HEADER _MAIL_BODY
            | error
            | MAIL_HEADER error
            | MAIL_HEADER _MAIL_BODY error
        """
        return self.defaultNodeClass(
            target='MAIL',
            option=option,
            names=names,
            values=values)

    def on_MAIL_HEADER(self, target, option, names, values):
        """
        MAIL_HEADER
            : MAIL_HEADER_LINES LT_RETURN_HEADER
        """
        return self.defaultNodeClass(
            target='MAIL_HEADER',
            option=option,
            names=names,
            values=values)

    def on_MAIL_HEADER_LINES(self, target, option, names, values):
        """
        MAIL_HEADER_LINES
            : LT_HEADER_ONE_LINE
            | MAIL_HEADER_LINES LT_HEADER_ONE_LINE
        """
        return self.defaultNodeClass(
            target='MAIL_HEADER_LINES',
            option=option,
            names=names,
            values=values)

    def on__MAIL_BODY(self, target, option, names, values):
        """
        _MAIL_BODY
            : MAIL_BODY
        """
        return self.defaultNodeClass(
            target='_MAIL_BODY',
            option=option,
            names=names,
            values=values)

    def on_MAIL_BODY(self, target, option, names, values):
        """
        MAIL_BODY
            : MLTYPE_DAILY_DAYTIME
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
        """
        return self.defaultNodeClass(
            target='MAIL_BODY',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_DAILY_NIGHT_OPE(self, target, option, names, values):
        """
        MLTYPE_DAILY_NIGHT_OPE
            : CMD_LINE_POS CMD_LINES_EGN_TP CMD_LINES_IDOL_I CMD_LINES_RUN_R CMD_LINES_HIREACH_C CMD_LINES_NIBURA_N CMD_LINE_HOUR_METER CMD_LINES_FUEL_F CMD_LINES_ENGN_W CMD_LINES_PUMP_U CMD_LINES_KADO_J CMD_LINES_AREA_NAIGAI_A CMD_LINES_ENGN_OIL_EC CMD_LINES_FUEL_FILTER_FC CMD_LINES_SADO_FILTER_HC CMD_LINES_SADO_CHANGE_LC CMD_LINES_OVER_OV CMD_LINES_FUEL_ONDO_FT CMD_LINES_FUEL_STATUS_FS CMD_LINES_NENPI CMD_SET_TIER4A_V7 CMD_LINES_SL CMD_LINES_VE CMD_LINES_TD CMD_LINES_X1 CMD_LINES_NUMSIGN
        """
        return self.defaultNodeClass(
            target='MLTYPE_DAILY_NIGHT_OPE',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_ONLY_POS(self, target, option, names, values):
        """
        MLTYPE_ONLY_POS
            : CMD_LINE_POS
        """
        return self.defaultNodeClass(
            target='MLTYPE_ONLY_POS',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_DAILY_NIGHT_NON_OPE(self, target, option, names, values):
        """
        MLTYPE_DAILY_NIGHT_NON_OPE
            : CMD_LINE_POS CMD_LINES_AREA_NAIGAI_A CMD_LINES_VE CMD_LINES_TD CMD_LINES_NUMSIGN
        """
        return self.defaultNodeClass(
            target='MLTYPE_DAILY_NIGHT_NON_OPE',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_DAILY_DAYTIME(self, target, option, names, values):
        """
        MLTYPE_DAILY_DAYTIME
            : CMD_LINE_POS CMD_LINES_FUEL_F CMD_LINES_NUMSIGN
        """
        return self.defaultNodeClass(
            target='MLTYPE_DAILY_DAYTIME',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_DAILY_NIGHT_EXCEPTION(self, target, option, names, values):
        """
        MLTYPE_DAILY_NIGHT_EXCEPTION
            : CMD_LINE_POS _CMD_LINES_EGN_TP CMD_LINES_NUMSIGN
        """
        return self.defaultNodeClass(
            target='MLTYPE_DAILY_NIGHT_EXCEPTION',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_RESPONSE_RT(self, target, option, names, values):
        """
        MLTYPE_RESPONSE_RT
            : CMD_LINE_POS CMD_LINE_EG CMD_LINES_FUEL_F CMD_LINES_FUEL_ONDO_FT CMD_LINES_FUEL_STATUS_FS CMD_LINES_XX
        """
        return self.defaultNodeClass(
            target='MLTYPE_RESPONSE_RT',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_ALARM_SC(self, target, option, names, values):
        """
        MLTYPE_ALARM_SC
            : CMD_LINE_ALARM_SC
        """
        return self.defaultNodeClass(
            target='MLTYPE_ALARM_SC',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_ALARM_SA(self, target, option, names, values):
        """
        MLTYPE_ALARM_SA
            : CMD_LINE_ALARM_SA CMD_LINE_POS
        """
        return self.defaultNodeClass(
            target='MLTYPE_ALARM_SA',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_ALARM_BT(self, target, option, names, values):
        """
        MLTYPE_ALARM_BT
            : CMD_LINE_ALARM_BT CMD_LINE_POS
        """
        return self.defaultNodeClass(
            target='MLTYPE_ALARM_BT',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_RESPONSE_AM(self, target, option, names, values):
        """
        MLTYPE_RESPONSE_AM
            : CMD_LINE_AM_OF CMD_LINE_AM_ON CMD_LINE_AM
        """
        return self.defaultNodeClass(
            target='MLTYPE_RESPONSE_AM',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_RESPONSE_CL(self, target, option, names, values):
        """
        MLTYPE_RESPONSE_CL
            : CMD_LINE_CL
        """
        return self.defaultNodeClass(
            target='MLTYPE_RESPONSE_CL',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_RESPONSE_CM0(self, target, option, names, values):
        """
        MLTYPE_RESPONSE_CM0
            : CMD_LINE_CM0
        """
        return self.defaultNodeClass(
            target='MLTYPE_RESPONSE_CM0',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_RESPONSE_CM1(self, target, option, names, values):
        """
        MLTYPE_RESPONSE_CM1
            : CMD_LINE_CM1
        """
        return self.defaultNodeClass(
            target='MLTYPE_RESPONSE_CM1',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_RESPONSE_CT0(self, target, option, names, values):
        """
        MLTYPE_RESPONSE_CT0
            : CMD_LINE_POS CMD_LINE_D0 CMD_LINE_D1 CMD_LINE_D2 CMD_LINE_D3 CMD_LINES_FUEL_F
        """
        return self.defaultNodeClass(
            target='MLTYPE_RESPONSE_CT0',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_RESPONSE_CT1(self, target, option, names, values):
        """
        MLTYPE_RESPONSE_CT1
            : CMD_LINE_M0 CMD_LINE_M1 CMD_LINE_M2 CMD_LINE_M3 CMD_LINE_M4 CMD_LINE_M5 CMD_LINE_M6 CMD_LINE_M7 CMD_LINE_M8
        """
        return self.defaultNodeClass(
            target='MLTYPE_RESPONSE_CT1',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_AMNG(self, target, option, names, values):
        """
        MLTYPE_AMNG
            : CMD_LINE_AMNG
        """
        return self.defaultNodeClass(
            target='MLTYPE_AMNG',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_HSOK(self, target, option, names, values):
        """
        MLTYPE_HSOK
            : CMD_LINE_HSOK
        """
        return self.defaultNodeClass(
            target='MLTYPE_HSOK',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_HSNG(self, target, option, names, values):
        """
        MLTYPE_HSNG
            : CMD_LINE_HSNG
        """
        return self.defaultNodeClass(
            target='MLTYPE_HSNG',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_HEOK(self, target, option, names, values):
        """
        MLTYPE_HEOK
            : CMD_LINE_HEOK
        """
        return self.defaultNodeClass(
            target='MLTYPE_HEOK',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_HENG(self, target, option, names, values):
        """
        MLTYPE_HENG
            : CMD_LINE_HENG
        """
        return self.defaultNodeClass(
            target='MLTYPE_HENG',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_HFOK(self, target, option, names, values):
        """
        MLTYPE_HFOK
            : CMD_LINE_HFOK
        """
        return self.defaultNodeClass(
            target='MLTYPE_HFOK',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_HFNG(self, target, option, names, values):
        """
        MLTYPE_HFNG
            : CMD_LINE_HFNG
        """
        return self.defaultNodeClass(
            target='MLTYPE_HFNG',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_HHOK(self, target, option, names, values):
        """
        MLTYPE_HHOK
            : CMD_LINE_HHOK
        """
        return self.defaultNodeClass(
            target='MLTYPE_HHOK',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_HHNG(self, target, option, names, values):
        """
        MLTYPE_HHNG
            : CMD_LINE_HHNG
        """
        return self.defaultNodeClass(
            target='MLTYPE_HHNG',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_HLOK(self, target, option, names, values):
        """
        MLTYPE_HLOK
            : CMD_LINE_HLOK
        """
        return self.defaultNodeClass(
            target='MLTYPE_HLOK',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_HLNG(self, target, option, names, values):
        """
        MLTYPE_HLNG
            : CMD_LINE_HLNG
        """
        return self.defaultNodeClass(
            target='MLTYPE_HLNG',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_RESPONSE_AC(self, target, option, names, values):
        """
        MLTYPE_RESPONSE_AC
            : CMD_LINES_AH CMD_LINES_PN CMD_LINES_VR
        """
        return self.defaultNodeClass(
            target='MLTYPE_RESPONSE_AC',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_WARNING(self, target, option, names, values):
        """
        MLTYPE_WARNING
            : _CMD_LINES_XX
        """
        return self.defaultNodeClass(
            target='MLTYPE_WARNING',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_SD(self, target, option, names, values):
        """
        MLTYPE_SD
            : CMD_LINE_SD_1 CMD_LINES_SD_2 CMD_LINE_SD_3
        """
        return self.defaultNodeClass(
            target='MLTYPE_SD',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_RM(self, target, option, names, values):
        """
        MLTYPE_RM
            : CMD_LINE_PN CMD_LINE_V CMD_LINE_EA CMD_LINE_PA CMD_LINE_PB CMD_LINE_PC CMD_LINE_UA CMD_LINE_UB CMD_LINE_ST
        """
        return self.defaultNodeClass(
            target='MLTYPE_RM',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_XX_V7(self, target, option, names, values):
        """
        MLTYPE_XX_V7
            : CMD_LINE_XX_V7
        """
        return self.defaultNodeClass(
            target='MLTYPE_XX_V7',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_TD(self, target, option, names, values):
        """
        MLTYPE_TD
            : CMD_LINE_RES_TD
        """
        return self.defaultNodeClass(
            target='MLTYPE_TD',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_DAILY_OPE(self, target, option, names, values):
        """
        MLTYPE_DAILY_OPE
            : CMD_LINE_POS CMD_LINE_HA CMD_LINE_AREA_NAIGAI_A CMD_LINE_LK CMD_LINE_TD CMD_LINE_YD CMD_LINE_OT CMD_LINE_M CMD_LINE_HOUR_METER CMD_LINE_ENGN_OIL_EC CMD_LINE_FUEL_FILTER_FC CMD_LINE_SADO_FILTER_HC CMD_LINE_SADO_CHANGE_LC CMD_LINE_FUEL_F CMD_LINE_FUEL_ONDO_FT CMD_LINE_FUEL_STATUS_FS CMD_LINE_SL CMD_LINE_IDOL_I CMD_LINE_RUN_R CMD_LINE_NIBURA_N CMD_LINE_HIREACH_C CMD_LINE_OVER_OV CMD_LINE_SW CMD_LINE_ENGN_W CMD_LINE_PUMP_U CMD_LINE_DA CMD_LINE_MC CMD_LINE_MT CMD_LINE_JH CMD_LINE_JS CMD_LINE_JE CMD_LINE_AB CMD_LINES_VE CMD_LINES_TC CMD_LINES_X1 CMD_LINES_NUMSIGN
        """
        return self.defaultNodeClass(
            target='MLTYPE_DAILY_OPE',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_DAILY_NOPE(self, target, option, names, values):
        """
        MLTYPE_DAILY_NOPE
            : CMD_LINE_POS CMD_LINE_HA CMD_LINE_AREA_NAIGAI_A CMD_LINE_TD CMD_LINE_YD CMD_LINES_VE CMD_LINES_NUMSIGN
        """
        return self.defaultNodeClass(
            target='MLTYPE_DAILY_NOPE',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_ALARM_SS(self, target, option, names, values):
        """
        MLTYPE_ALARM_SS
            : CMD_LINE_SS CMD_LINE_POS
        """
        return self.defaultNodeClass(
            target='MLTYPE_ALARM_SS',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_ALARM_SR(self, target, option, names, values):
        """
        MLTYPE_ALARM_SR
            : CMD_LINE_SR CMD_LINE_POS
        """
        return self.defaultNodeClass(
            target='MLTYPE_ALARM_SR',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_ALARM_SG(self, target, option, names, values):
        """
        MLTYPE_ALARM_SG
            : CMD_LINE_SG CMD_LINE_POS
        """
        return self.defaultNodeClass(
            target='MLTYPE_ALARM_SG',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_ALARM_SU(self, target, option, names, values):
        """
        MLTYPE_ALARM_SU
            : CMD_LINE_SU CMD_LINE_POS
        """
        return self.defaultNodeClass(
            target='MLTYPE_ALARM_SU',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_RES_REMOTE_DL(self, target, option, names, values):
        """
        MLTYPE_RES_REMOTE_DL
            : CMD_LINE_RES_REMOTE_DL
        """
        return self.defaultNodeClass(
            target='MLTYPE_RES_REMOTE_DL',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_ASTRSK(self, target, option, names, values):
        """
        MLTYPE_ASTRSK
            : CMD_LINE_ASTRSK1 _CMD_LINES_ASTRSK2
        """
        return self.defaultNodeClass(
            target='MLTYPE_ASTRSK',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_FDFD(self, target, option, names, values):
        """
        MLTYPE_FDFD
            : _CMD_LINES_FDFQFR CMD_LINES_NUMSIGN
        """
        return self.defaultNodeClass(
            target='MLTYPE_FDFD',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_HDHQHP(self, target, option, names, values):
        """
        MLTYPE_HDHQHP
            : _CMD_LINES_HDHQHP CMD_LINES_NUMSIGN
        """
        return self.defaultNodeClass(
            target='MLTYPE_HDHQHP',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_LKOK(self, target, option, names, values):
        """
        MLTYPE_LKOK
            : CMD_LINE_LKOK
        """
        return self.defaultNodeClass(
            target='MLTYPE_LKOK',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_AR(self, target, option, names, values):
        """
        MLTYPE_AR
            : _CMD_LINES_AR
        """
        return self.defaultNodeClass(
            target='MLTYPE_AR',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_AE(self, target, option, names, values):
        """
        MLTYPE_AE
            : _CMD_LINES_AE
        """
        return self.defaultNodeClass(
            target='MLTYPE_AE',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_RR(self, target, option, names, values):
        """
        MLTYPE_RR
            : _CMD_LINES_RR
        """
        return self.defaultNodeClass(
            target='MLTYPE_RR',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_SSID(self, target, option, names, values):
        """
        MLTYPE_SSID
            : CMD_LINE_SSID
        """
        return self.defaultNodeClass(
            target='MLTYPE_SSID',
            option=option,
            names=names,
            values=values)

    def on_MLTYPE_KL(self, target, option, names, values):
        """
        MLTYPE_KL
            : _CMD_LINES_KL
        """
        return self.defaultNodeClass(
            target='MLTYPE_KL',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINES_EGN_TP(self, target, option, names, values):
        """
        CMD_LINES_EGN_TP
            : | _CMD_LINES_EGN_TP
        """
        return self.defaultNodeClass(
            target='CMD_LINES_EGN_TP',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINES_AH(self, target, option, names, values):
        """
        CMD_LINES_AH
            : _CMD_LINES_AH
        """
        return self.defaultNodeClass(
            target='CMD_LINES_AH',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINES_XX(self, target, option, names, values):
        """
        CMD_LINES_XX
            : | _CMD_LINES_XX
        """
        return self.defaultNodeClass(
            target='CMD_LINES_XX',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINES_PN(self, target, option, names, values):
        """
        CMD_LINES_PN
            : | _CMD_LINES_PN
        """
        return self.defaultNodeClass(
            target='CMD_LINES_PN',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINES_VR(self, target, option, names, values):
        """
        CMD_LINES_VR
            : | _CMD_LINES_VR
        """
        return self.defaultNodeClass(
            target='CMD_LINES_VR',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINES_SD_2(self, target, option, names, values):
        """
        CMD_LINES_SD_2
            : | _CMD_LINES_SD_2
        """
        return self.defaultNodeClass(
            target='CMD_LINES_SD_2',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINES_KADO_J(self, target, option, names, values):
        """
        CMD_LINES_KADO_J
            : | CMD_LINE_KADO_J
        """
        return self.defaultNodeClass(
            target='CMD_LINES_KADO_J',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINES_AREA_NAIGAI_A(self, target, option, names, values):
        """
        CMD_LINES_AREA_NAIGAI_A
            : | CMD_LINE_AREA_NAIGAI_A
        """
        return self.defaultNodeClass(
            target='CMD_LINES_AREA_NAIGAI_A',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINES_ENGN_OIL_EC(self, target, option, names, values):
        """
        CMD_LINES_ENGN_OIL_EC
            : | CMD_LINE_ENGN_OIL_EC
        """
        return self.defaultNodeClass(
            target='CMD_LINES_ENGN_OIL_EC',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINES_FUEL_FILTER_FC(self, target, option, names, values):
        """
        CMD_LINES_FUEL_FILTER_FC
            : | CMD_LINE_FUEL_FILTER_FC
        """
        return self.defaultNodeClass(
            target='CMD_LINES_FUEL_FILTER_FC',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINES_SADO_FILTER_HC(self, target, option, names, values):
        """
        CMD_LINES_SADO_FILTER_HC
            : | CMD_LINE_SADO_FILTER_HC
        """
        return self.defaultNodeClass(
            target='CMD_LINES_SADO_FILTER_HC',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINES_SADO_CHANGE_LC(self, target, option, names, values):
        """
        CMD_LINES_SADO_CHANGE_LC
            : | CMD_LINE_SADO_CHANGE_LC
        """
        return self.defaultNodeClass(
            target='CMD_LINES_SADO_CHANGE_LC',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINES_OVER_OV(self, target, option, names, values):
        """
        CMD_LINES_OVER_OV
            : | CMD_LINE_OVER_OV
        """
        return self.defaultNodeClass(
            target='CMD_LINES_OVER_OV',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINES_FUEL_ONDO_FT(self, target, option, names, values):
        """
        CMD_LINES_FUEL_ONDO_FT
            : | CMD_LINE_FUEL_ONDO_FT
        """
        return self.defaultNodeClass(
            target='CMD_LINES_FUEL_ONDO_FT',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINES_FUEL_STATUS_FS(self, target, option, names, values):
        """
        CMD_LINES_FUEL_STATUS_FS
            : | CMD_LINE_FUEL_STATUS_FS
        """
        return self.defaultNodeClass(
            target='CMD_LINES_FUEL_STATUS_FS',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINES_NENPI(self, target, option, names, values):
        """
        CMD_LINES_NENPI
            : | CMD_LINE_NENPI
        """
        return self.defaultNodeClass(
            target='CMD_LINES_NENPI',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINES_IDOL_I(self, target, option, names, values):
        """
        CMD_LINES_IDOL_I
            : | CMD_LINE_IDOL_I
        """
        return self.defaultNodeClass(
            target='CMD_LINES_IDOL_I',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINES_RUN_R(self, target, option, names, values):
        """
        CMD_LINES_RUN_R
            : | CMD_LINE_RUN_R
        """
        return self.defaultNodeClass(
            target='CMD_LINES_RUN_R',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINES_HIREACH_C(self, target, option, names, values):
        """
        CMD_LINES_HIREACH_C
            : | CMD_LINE_HIREACH_C
        """
        return self.defaultNodeClass(
            target='CMD_LINES_HIREACH_C',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINES_NIBURA_N(self, target, option, names, values):
        """
        CMD_LINES_NIBURA_N
            : | CMD_LINE_NIBURA_N
        """
        return self.defaultNodeClass(
            target='CMD_LINES_NIBURA_N',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINES_FUEL_F(self, target, option, names, values):
        """
        CMD_LINES_FUEL_F
            : | CMD_LINE_FUEL_F
        """
        return self.defaultNodeClass(
            target='CMD_LINES_FUEL_F',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINES_ENGN_W(self, target, option, names, values):
        """
        CMD_LINES_ENGN_W
            : | CMD_LINE_ENGN_W
        """
        return self.defaultNodeClass(
            target='CMD_LINES_ENGN_W',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINES_PUMP_U(self, target, option, names, values):
        """
        CMD_LINES_PUMP_U
            : | CMD_LINE_PUMP_U
        """
        return self.defaultNodeClass(
            target='CMD_LINES_PUMP_U',
            option=option,
            names=names,
            values=values)

    def on_CMD_SET_TIER4A_V7(self, target, option, names, values):
        """
        CMD_SET_TIER4A_V7
            : | _CMD_SET_TIER4A_V7
        """
        return self.defaultNodeClass(
            target='CMD_SET_TIER4A_V7',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINES_SL(self, target, option, names, values):
        """
        CMD_LINES_SL
            : | CMD_LINE_SL
        """
        return self.defaultNodeClass(
            target='CMD_LINES_SL',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINES_TD(self, target, option, names, values):
        """
        CMD_LINES_TD
            : | CMD_LINE_TD
        """
        return self.defaultNodeClass(
            target='CMD_LINES_TD',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINES_X1(self, target, option, names, values):
        """
        CMD_LINES_X1
            : | _CMD_LINES_X1
        """
        return self.defaultNodeClass(
            target='CMD_LINES_X1',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINES_NUMSIGN(self, target, option, names, values):
        """
        CMD_LINES_NUMSIGN
            : | _CMD_LINES_NUMSIGN
        """
        return self.defaultNodeClass(
            target='CMD_LINES_NUMSIGN',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINES_VE(self, target, option, names, values):
        """
        CMD_LINES_VE
            : | CMD_LINE_VE
        """
        return self.defaultNodeClass(
            target='CMD_LINES_VE',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINES_TC(self, target, option, names, values):
        """
        CMD_LINES_TC
            : | CMD_LINE_TC
        """
        return self.defaultNodeClass(
            target='CMD_LINES_TC',
            option=option,
            names=names,
            values=values)

    def on__CMD_LINES_EGN_TP(self, target, option, names, values):
        """
        _CMD_LINES_EGN_TP
            : CMD_LINE_EGN_T
            | CMD_LINE_EGN_P
            | _CMD_LINES_EGN_TP CMD_LINE_EGN_T
            | _CMD_LINES_EGN_TP CMD_LINE_EGN_P
        """
        return self.defaultNodeClass(
            target='_CMD_LINES_EGN_TP',
            option=option,
            names=names,
            values=values)

    def on__CMD_LINES_AH(self, target, option, names, values):
        """
        _CMD_LINES_AH
            : _CMD_LINES_AH CMD_LINE_AH
            | CMD_LINE_AH
        """
        return self.defaultNodeClass(
            target='_CMD_LINES_AH',
            option=option,
            names=names,
            values=values)

    def on__CMD_LINES_XX(self, target, option, names, values):
        """
        _CMD_LINES_XX
            : _CMD_LINES_XX CMD_LINE_XX
            | CMD_LINE_XX
        """
        return self.defaultNodeClass(
            target='_CMD_LINES_XX',
            option=option,
            names=names,
            values=values)

    def on__CMD_LINES_PN(self, target, option, names, values):
        """
        _CMD_LINES_PN
            : _CMD_LINES_PN CMD_LINE_PN
            | CMD_LINE_PN
        """
        return self.defaultNodeClass(
            target='_CMD_LINES_PN',
            option=option,
            names=names,
            values=values)

    def on__CMD_LINES_VR(self, target, option, names, values):
        """
        _CMD_LINES_VR
            : _CMD_LINES_VR CMD_LINE_VR
            | CMD_LINE_VR
        """
        return self.defaultNodeClass(
            target='_CMD_LINES_VR',
            option=option,
            names=names,
            values=values)

    def on__CMD_LINES_SD_2(self, target, option, names, values):
        """
        _CMD_LINES_SD_2
            : _CMD_LINES_SD_2 CMD_LINE_SD_2
            | CMD_LINE_SD_2
        """
        return self.defaultNodeClass(
            target='_CMD_LINES_SD_2',
            option=option,
            names=names,
            values=values)

    def on__CMD_LINES_X1(self, target, option, names, values):
        """
        _CMD_LINES_X1
            : CMD_LINE_X1
            | _CMD_LINES_X1 CMD_LINE_X1
        """
        return self.defaultNodeClass(
            target='_CMD_LINES_X1',
            option=option,
            names=names,
            values=values)

    def on__CMD_LINES_ASTRSK2(self, target, option, names, values):
        """
        _CMD_LINES_ASTRSK2
            : CMD_LINE_ASTRSK2
            | _CMD_LINES_ASTRSK2 CMD_LINE_ASTRSK2
        """
        return self.defaultNodeClass(
            target='_CMD_LINES_ASTRSK2',
            option=option,
            names=names,
            values=values)

    def on__CMD_LINES_NUMSIGN(self, target, option, names, values):
        """
        _CMD_LINES_NUMSIGN
            : CMD_LINE_NUMSIGN
            | _CMD_LINES_NUMSIGN CMD_LINE_NUMSIGN
        """
        return self.defaultNodeClass(
            target='_CMD_LINES_NUMSIGN',
            option=option,
            names=names,
            values=values)

    def on__CMD_LINES_FDFQFR(self, target, option, names, values):
        """
        _CMD_LINES_FDFQFR
            : CMD_LINE_FD
            | CMD_LINE_FQ
            | CMD_LINE_FR
            | _CMD_LINES_FDFQFR CMD_LINE_FQ
            | _CMD_LINES_FDFQFR CMD_LINE_FR
        """
        return self.defaultNodeClass(
            target='_CMD_LINES_FDFQFR',
            option=option,
            names=names,
            values=values)

    def on__CMD_LINES_HDHQHP(self, target, option, names, values):
        """
        _CMD_LINES_HDHQHP
            : CMD_LINE_HD
            | CMD_LINE_HQ
            | CMD_LINE_HP
            | _CMD_LINES_HDHQHP CMD_LINE_HQ
            | _CMD_LINES_HDHQHP CMD_LINE_HP
        """
        return self.defaultNodeClass(
            target='_CMD_LINES_HDHQHP',
            option=option,
            names=names,
            values=values)

    def on__CMD_LINES_AE(self, target, option, names, values):
        """
        _CMD_LINES_AE
            : CMD_LINE_AE
            | _CMD_LINES_AE CMD_LINE_AE
        """
        return self.defaultNodeClass(
            target='_CMD_LINES_AE',
            option=option,
            names=names,
            values=values)

    def on__CMD_LINES_AR(self, target, option, names, values):
        """
        _CMD_LINES_AR
            : CMD_LINE_AR
            | _CMD_LINES_AR CMD_LINE_AR
        """
        return self.defaultNodeClass(
            target='_CMD_LINES_AR',
            option=option,
            names=names,
            values=values)

    def on__CMD_LINES_RR(self, target, option, names, values):
        """
        _CMD_LINES_RR
            : CMD_LINE_RR
            | _CMD_LINES_RR CMD_LINE_RR
        """
        return self.defaultNodeClass(
            target='_CMD_LINES_RR',
            option=option,
            names=names,
            values=values)

    def on__CMD_LINES_KL(self, target, option, names, values):
        """
        _CMD_LINES_KL
            : CMD_LINE_KL
            | _CMD_LINES_KL CMD_LINE_KL
        """
        return self.defaultNodeClass(
            target='_CMD_LINES_KL',
            option=option,
            names=names,
            values=values)

    def on__CMD_SET_TIER4A_V7(self, target, option, names, values):
        """
        _CMD_SET_TIER4A_V7
            : CMD_LINE_MC CMD_LINE_MT CMD_LINE_SW CMD_LINE_DA
        """
        return self.defaultNodeClass(
            target='_CMD_SET_TIER4A_V7',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_POS(self, target, option, names, values):
        """
        CMD_LINE_POS
            : CMD_TOKEN_P LT_DOUBLE LT_COMMA LT_DOUBLE LT_COMMA LT_INTVAL LT_RETURN
            | CMD_TOKEN_P LT_POS_ERR LT_COMMA LT_POS_ERR LT_COMMA LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_POS',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_HOUR_METER(self, target, option, names, values):
        """
        CMD_LINE_HOUR_METER
            : CMD_TOKEN_H LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_HOUR_METER',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_AREA_NAIGAI_A(self, target, option, names, values):
        """
        CMD_LINE_AREA_NAIGAI_A
            : CMD_TOKEN_A LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_AREA_NAIGAI_A',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_ALARM_SC(self, target, option, names, values):
        """
        CMD_LINE_ALARM_SC
            : CMD_TOKEN_SC LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_ALARM_SC',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_ALARM_SA(self, target, option, names, values):
        """
        CMD_LINE_ALARM_SA
            : CMD_TOKEN_SA LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_ALARM_SA',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_ALARM_BT(self, target, option, names, values):
        """
        CMD_LINE_ALARM_BT
            : CMD_TOKEN_BT LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_ALARM_BT',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_EG(self, target, option, names, values):
        """
        CMD_LINE_EG
            : CMD_TOKEN_EG LT_ON LT_RETURN
            | CMD_TOKEN_EG LT_OFF LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_EG',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_AM_ON(self, target, option, names, values):
        """
        CMD_LINE_AM_ON
            : CMD_TOKEN_AMON LT_INTVAL LT_OKNG LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_AM_ON',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_AM_OF(self, target, option, names, values):
        """
        CMD_LINE_AM_OF
            : CMD_TOKEN_AMOF LT_INTVAL LT_OKNG LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_AM_OF',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_AM(self, target, option, names, values):
        """
        CMD_LINE_AM
            : CMD_TOKEN_AM LT_INTVAL LT_OKNG LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_AM',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_CL(self, target, option, names, values):
        """
        CMD_LINE_CL
            : CMD_TOKEN_CL LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_OKNG LT_RETURN
            | CMD_TOKEN_CL LT_DOUBLE LT_COMMA LT_DOUBLE LT_COMMA LT_DOUBLE LT_COMMA LT_DOUBLE LT_OKNG LT_RETURN
            | CMD_TOKEN_CL LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_RETURN_2 LT_OKNG LT_RETURN
            | CMD_TOKEN_CL LT_DOUBLE LT_COMMA LT_DOUBLE LT_COMMA LT_DOUBLE LT_COMMA LT_DOUBLE LT_RETURN_2 LT_OKNG LT_RETURN
            | CMD_TOKEN_CL LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_RETURN LT_OKNG LT_RETURN
            | CMD_TOKEN_CL LT_DOUBLE LT_COMMA LT_DOUBLE LT_COMMA LT_DOUBLE LT_COMMA LT_DOUBLE LT_RETURN LT_OKNG LT_RETURN
            | CMD_TOKEN_CL LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_RETURN_2 LT_RETURN LT_OKNG LT_RETURN
            | CMD_TOKEN_CL LT_DOUBLE LT_COMMA LT_DOUBLE LT_COMMA LT_DOUBLE LT_COMMA LT_DOUBLE LT_RETURN_2 LT_RETURN LT_OKNG LT_RETURN
            | CMD_TOKEN_CL LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_RETURN LT_RETURN_2 LT_OKNG LT_RETURN
            | CMD_TOKEN_CL LT_DOUBLE LT_COMMA LT_DOUBLE LT_COMMA LT_DOUBLE LT_COMMA LT_DOUBLE LT_RETURN LT_RETURN_2 LT_OKNG LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_CL',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_CM0(self, target, option, names, values):
        """
        CMD_LINE_CM0
            : CMD_TOKEN_CM0 LT_OKNG LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_CM0',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_CM1(self, target, option, names, values):
        """
        CMD_LINE_CM1
            : CMD_TOKEN_CM1 LT_OKNG LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_CM1',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_D0(self, target, option, names, values):
        """
        CMD_LINE_D0
            : CMD_TOKEN_D0 LT_COMMA LT_TEXT_EX LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_D0',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_D1(self, target, option, names, values):
        """
        CMD_LINE_D1
            : CMD_TOKEN_D1 LT_COMMA LT_IP_ADDR LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_D1',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_D2(self, target, option, names, values):
        """
        CMD_LINE_D2
            : CMD_TOKEN_D2 LT_COMMA LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_D2',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_D3(self, target, option, names, values):
        """
        CMD_LINE_D3
            : CMD_TOKEN_D3 LT_COMMA LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_D3',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_M0(self, target, option, names, values):
        """
        CMD_LINE_M0
            : CMD_TOKEN_M0 LT_COMMA LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_M0',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_M1(self, target, option, names, values):
        """
        CMD_LINE_M1
            : CMD_TOKEN_M1 LT_COMMA LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_M1',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_M2(self, target, option, names, values):
        """
        CMD_LINE_M2
            : CMD_TOKEN_M2 LT_COMMA LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_M2',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_M3(self, target, option, names, values):
        """
        CMD_LINE_M3
            : CMD_TOKEN_M3 LT_COMMA LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_M3',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_M4(self, target, option, names, values):
        """
        CMD_LINE_M4
            : CMD_TOKEN_M4 LT_COMMA LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_M4',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_M5(self, target, option, names, values):
        """
        CMD_LINE_M5
            : CMD_TOKEN_M5 LT_COMMA LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_M5',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_M6(self, target, option, names, values):
        """
        CMD_LINE_M6
            : CMD_TOKEN_M6 LT_COMMA LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_M6',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_M7(self, target, option, names, values):
        """
        CMD_LINE_M7
            : CMD_TOKEN_M7 LT_COMMA LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_M7',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_M8(self, target, option, names, values):
        """
        CMD_LINE_M8
            : CMD_TOKEN_M8 LT_COMMA LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_M8',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_EGN_T(self, target, option, names, values):
        """
        CMD_LINE_EGN_T
            : CMD_TOKEN_T LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_EGN_T',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_EGN_P(self, target, option, names, values):
        """
        CMD_LINE_EGN_P
            : CMD_TOKEN_P LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_EGN_P',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_IDOL_I(self, target, option, names, values):
        """
        CMD_LINE_IDOL_I
            : CMD_TOKEN_I LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_IDOL_I',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_RUN_R(self, target, option, names, values):
        """
        CMD_LINE_RUN_R
            : CMD_TOKEN_R LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_RUN_R',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_HIREACH_C(self, target, option, names, values):
        """
        CMD_LINE_HIREACH_C
            : CMD_TOKEN_C LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_HIREACH_C',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_NIBURA_N(self, target, option, names, values):
        """
        CMD_LINE_NIBURA_N
            : CMD_TOKEN_N LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_NIBURA_N',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_FUEL_F(self, target, option, names, values):
        """
        CMD_LINE_FUEL_F
            : CMD_TOKEN_F LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_FUEL_F',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_ENGN_W(self, target, option, names, values):
        """
        CMD_LINE_ENGN_W
            : CMD_TOKEN_W LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_ENGN_W',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_PUMP_U(self, target, option, names, values):
        """
        CMD_LINE_PUMP_U
            : CMD_TOKEN_U LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_PUMP_U',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_KADO_J(self, target, option, names, values):
        """
        CMD_LINE_KADO_J
            : CMD_TOKEN_J LT_RETURN
            | CMD_TOKEN_J LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_KADO_J',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_ENGN_OIL_EC(self, target, option, names, values):
        """
        CMD_LINE_ENGN_OIL_EC
            : CMD_TOKEN_EC LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_ENGN_OIL_EC',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_FUEL_FILTER_FC(self, target, option, names, values):
        """
        CMD_LINE_FUEL_FILTER_FC
            : CMD_TOKEN_FC LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_FUEL_FILTER_FC',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_SADO_FILTER_HC(self, target, option, names, values):
        """
        CMD_LINE_SADO_FILTER_HC
            : CMD_TOKEN_HC LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_SADO_FILTER_HC',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_SADO_CHANGE_LC(self, target, option, names, values):
        """
        CMD_LINE_SADO_CHANGE_LC
            : CMD_TOKEN_LC LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_SADO_CHANGE_LC',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_OVER_OV(self, target, option, names, values):
        """
        CMD_LINE_OVER_OV
            : CMD_TOKEN_OV LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_OVER_OV',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_FUEL_ONDO_FT(self, target, option, names, values):
        """
        CMD_LINE_FUEL_ONDO_FT
            : CMD_TOKEN_FT LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_FUEL_ONDO_FT',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_FUEL_STATUS_FS(self, target, option, names, values):
        """
        CMD_LINE_FUEL_STATUS_FS
            : CMD_TOKEN_FS LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_FUEL_STATUS_FS',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_AMNG(self, target, option, names, values):
        """
        CMD_LINE_AMNG
            : CMD_TOKEN_AM LT_OKNG LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_AMNG',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_HSOK(self, target, option, names, values):
        """
        CMD_LINE_HSOK
            : CMD_TOKEN_HS LT_INTVAL LT_OKNG LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_HSOK',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_HSNG(self, target, option, names, values):
        """
        CMD_LINE_HSNG
            : CMD_TOKEN_HS LT_OKNG LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_HSNG',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_HEOK(self, target, option, names, values):
        """
        CMD_LINE_HEOK
            : CMD_TOKEN_HE LT_INTVAL LT_OKNG LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_HEOK',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_HENG(self, target, option, names, values):
        """
        CMD_LINE_HENG
            : CMD_TOKEN_HE LT_OKNG LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_HENG',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_HFOK(self, target, option, names, values):
        """
        CMD_LINE_HFOK
            : CMD_TOKEN_HF LT_INTVAL LT_OKNG LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_HFOK',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_HFNG(self, target, option, names, values):
        """
        CMD_LINE_HFNG
            : CMD_TOKEN_HF LT_OKNG LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_HFNG',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_HHOK(self, target, option, names, values):
        """
        CMD_LINE_HHOK
            : CMD_TOKEN_HH LT_INTVAL LT_OKNG LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_HHOK',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_HHNG(self, target, option, names, values):
        """
        CMD_LINE_HHNG
            : CMD_TOKEN_HH LT_OKNG LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_HHNG',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_HLOK(self, target, option, names, values):
        """
        CMD_LINE_HLOK
            : CMD_TOKEN_HL LT_INTVAL LT_OKNG LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_HLOK',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_HLNG(self, target, option, names, values):
        """
        CMD_LINE_HLNG
            : CMD_TOKEN_HL LT_OKNG LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_HLNG',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_AH(self, target, option, names, values):
        """
        CMD_LINE_AH
            : CMD_TOKEN_AH LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_COMMA LT_NUMERIC LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_AH',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_PN(self, target, option, names, values):
        """
        CMD_LINE_PN
            : CMD_TOKEN_PN LT_TEXT_EX LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_PN',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_VR(self, target, option, names, values):
        """
        CMD_LINE_VR
            : CMD_TOKEN_VR LT_TEXT_EX LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_VR',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_XX(self, target, option, names, values):
        """
        CMD_LINE_XX
            : CMD_TOKEN_XX LT_INTVAL LT_COMMA LT_INTVAL LT_RETURN
            | CMD_TOKEN_XX LT_TEXT LT_COMMA LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_XX',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_XX_V7(self, target, option, names, values):
        """
        CMD_LINE_XX_V7
            : CMD_TOKEN_XX LT_INTVAL LT_COMMA LT_TEXT_EX LT_COMMA LT_INT10 LT_RETURN
            | CMD_TOKEN_XX LT_TEXT LT_COMMA LT_TEXT_EX LT_COMMA LT_INT10 LT_RETURN
            | CMD_TOKEN_XX LT_INTVAL LT_COMMA LT_TEXT_EX LT_COMMA LT_INT10 LT_COMMA LT_TEXT_EX LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_XX_V7',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_SD_1(self, target, option, names, values):
        """
        CMD_LINE_SD_1
            : CMD_TOKEN_SD_1 LT_INT2 LT_COMMA LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_SD_1',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_SD_2(self, target, option, names, values):
        """
        CMD_LINE_SD_2
            : CMD_TOKEN_SD_2 LT_TEXT_EX LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_SD_2',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_SD_3(self, target, option, names, values):
        """
        CMD_LINE_SD_3
            : CMD_TOKEN_SD_1 LT_INT2 LT_OKNG LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_SD_3',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_NENPI(self, target, option, names, values):
        """
        CMD_LINE_NENPI
            : CMD_TOKEN_NENPI LT_INTVAL LT_COMMA LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_NENPI',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_V(self, target, option, names, values):
        """
        CMD_LINE_V
            : CMD_TOKEN_V LT_TEXT_EX LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_V',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_EA(self, target, option, names, values):
        """
        CMD_LINE_EA
            : CMD_TOKEN_EA LT_TEXT_EX LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_EA',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_PA(self, target, option, names, values):
        """
        CMD_LINE_PA
            : CMD_TOKEN_PA LT_TEXT_EX LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_PA',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_PB(self, target, option, names, values):
        """
        CMD_LINE_PB
            : CMD_TOKEN_PB LT_TEXT_EX LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_PB',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_PC(self, target, option, names, values):
        """
        CMD_LINE_PC
            : CMD_TOKEN_PC LT_TEXT_EX LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_PC',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_UA(self, target, option, names, values):
        """
        CMD_LINE_UA
            : CMD_TOKEN_UA LT_TEXT_EX LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_UA',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_UB(self, target, option, names, values):
        """
        CMD_LINE_UB
            : CMD_TOKEN_UB LT_TEXT_EX LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_UB',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_SW(self, target, option, names, values):
        """
        CMD_LINE_SW
            : CMD_TOKEN_SW LT_TEXT_EX LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_SW',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_ST(self, target, option, names, values):
        """
        CMD_LINE_ST
            : CMD_TOKEN_ST LT_TEXT_EX LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_ST',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_MC(self, target, option, names, values):
        """
        CMD_LINE_MC
            : CMD_TOKEN_MC LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_RETURN
            | CMD_TOKEN_MC LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_MC',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_MT(self, target, option, names, values):
        """
        CMD_LINE_MT
            : CMD_TOKEN_MT LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_RETURN
            | CMD_TOKEN_MT LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_MT',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_DA(self, target, option, names, values):
        """
        CMD_LINE_DA
            : CMD_TOKEN_DA LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_DA',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_SL(self, target, option, names, values):
        """
        CMD_LINE_SL
            : CMD_TOKEN_SL LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_SL',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_TD(self, target, option, names, values):
        """
        CMD_LINE_TD
            : CMD_TOKEN_TD LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_TD',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_RES_TD(self, target, option, names, values):
        """
        CMD_LINE_RES_TD
            : CMD_TOKEN_TD LT_INTVAL LT_OKNG LT_RETURN
            | CMD_TOKEN_TD LT_OKNG LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_RES_TD',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_AE(self, target, option, names, values):
        """
        CMD_LINE_AE
            : CMD_TOKEN_AE LT_INTVAL LT_COMMA LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_AE',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_AR(self, target, option, names, values):
        """
        CMD_LINE_AR
            : CMD_TOKEN_AR LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_RETURN
            | CMD_TOKEN_AR LT_INTVAL LT_COMMA LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_AR',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_X1(self, target, option, names, values):
        """
        CMD_LINE_X1
            : CMD_TOKEN_X1 LT_TEXT_EX LT_RETURN
            | CMD_TOKEN_X1 LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_RETURN
            | CMD_TOKEN_X1 LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_RETURN
            | CMD_TOKEN_X1 LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_RETURN
            | CMD_TOKEN_X1 LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_RETURN
            | CMD_TOKEN_X1 LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_RETURN
            | CMD_TOKEN_X1 LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_RETURN
            | CMD_TOKEN_X1 LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_RETURN
            | CMD_TOKEN_X1 LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_RETURN
            | CMD_TOKEN_X1 LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_RETURN
            | CMD_TOKEN_X1 LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_RETURN
            | CMD_TOKEN_X1 LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_X1',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_HA(self, target, option, names, values):
        """
        CMD_LINE_HA
            : CMD_TOKEN_HA LT_TEXT_EX LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_HA',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_LK(self, target, option, names, values):
        """
        CMD_LINE_LK
            : CMD_TOKEN_LK LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_LK',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_YD(self, target, option, names, values):
        """
        CMD_LINE_YD
            : CMD_TOKEN_YD LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_YD',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_OT(self, target, option, names, values):
        """
        CMD_LINE_OT
            : CMD_TOKEN_OT LT_NUMERIC LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_OT',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_M(self, target, option, names, values):
        """
        CMD_LINE_M
            : CMD_TOKEN_M LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_M',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_JH(self, target, option, names, values):
        """
        CMD_LINE_JH
            : CMD_TOKEN_JH LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_JH',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_JS(self, target, option, names, values):
        """
        CMD_LINE_JS
            : CMD_TOKEN_JS LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_JS',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_JE(self, target, option, names, values):
        """
        CMD_LINE_JE
            : CMD_TOKEN_JE LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_JE',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_AB(self, target, option, names, values):
        """
        CMD_LINE_AB
            : CMD_TOKEN_AB LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_AB',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_SS(self, target, option, names, values):
        """
        CMD_LINE_SS
            : CMD_TOKEN_SS LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_SS',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_SR(self, target, option, names, values):
        """
        CMD_LINE_SR
            : CMD_TOKEN_SR LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_SR',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_SG(self, target, option, names, values):
        """
        CMD_LINE_SG
            : CMD_TOKEN_SG LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_SG',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_SU(self, target, option, names, values):
        """
        CMD_LINE_SU
            : CMD_TOKEN_SU LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_SU',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_RES_REMOTE_DL(self, target, option, names, values):
        """
        CMD_LINE_RES_REMOTE_DL
            : CMD_TOKEN_DG LT_OKNG LT_COMMA LT_TEXT_EX LT_COMMA LT_INTVAL LT_RETURN
            | CMD_TOKEN_DU LT_OKNG LT_COMMA LT_TEXT_EX LT_COMMA LT_INTVAL LT_RETURN
            | CMD_TOKEN_DC LT_OKNG LT_COMMA LT_TEXT_EX LT_COMMA LT_INTVAL LT_RETURN
            | CMD_TOKEN_DR LT_OKNG LT_COMMA LT_TEXT_EX LT_COMMA LT_INTVAL LT_RETURN
            | CMD_TOKEN_DR LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_RES_REMOTE_DL',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_ASTRSK1(self, target, option, names, values):
        """
        CMD_LINE_ASTRSK1
            : CMD_TOKEN_ASTRSK1 LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_RETURN
            | CMD_TOKEN_ASTRSK1 LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_RETURN
            | CMD_TOKEN_ASTRSK1 LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_RETURN
            | CMD_TOKEN_ASTRSK1 LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_RETURN
            | CMD_TOKEN_ASTRSK1 LT_TEXT_EX LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_ASTRSK1',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_ASTRSK2(self, target, option, names, values):
        """
        CMD_LINE_ASTRSK2
            : CMD_TOKEN_ASTRSK2 LT_TEXT LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_ASTRSK2',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_NUMSIGN(self, target, option, names, values):
        """
        CMD_LINE_NUMSIGN
            : CMD_TOKEN_NUMSIGN LT_TEXT_EX LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_NUMSIGN',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_HD(self, target, option, names, values):
        """
        CMD_LINE_HD
            : CMD_TOKEN_HD LT_OKNG LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_HD',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_HP(self, target, option, names, values):
        """
        CMD_LINE_HP
            : CMD_TOKEN_HP LT_TEXT_EX LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_HP',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_HQ(self, target, option, names, values):
        """
        CMD_LINE_HQ
            : CMD_TOKEN_HQ LT_TEXT_EX LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_HQ',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_FR(self, target, option, names, values):
        """
        CMD_LINE_FR
            : CMD_TOKEN_FR LT_TEXT_EX LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_FR',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_FD(self, target, option, names, values):
        """
        CMD_LINE_FD
            : CMD_TOKEN_FD LT_TEXT_EX LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_FD',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_FQ(self, target, option, names, values):
        """
        CMD_LINE_FQ
            : CMD_TOKEN_FQ LT_TEXT_EX LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_FQ',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_RR(self, target, option, names, values):
        """
        CMD_LINE_RR
            : CMD_TOKEN_RR LT_INTVAL LT_COMMA LT_TEXT_EX LT_RETURN
            | CMD_TOKEN_RR LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_RETURN
            | CMD_TOKEN_RR LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_RR',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_SSID(self, target, option, names, values):
        """
        CMD_LINE_SSID
            : CMD_TOKEN_SSID LT_OKNG LT_COMMA LT_INTVAL LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_SSID',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_LKOK(self, target, option, names, values):
        """
        CMD_LINE_LKOK
            : CMD_TOKEN_LK LT_INTVAL LT_OKNG LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_LKOK',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_VE(self, target, option, names, values):
        """
        CMD_LINE_VE
            : CMD_TOKEN_VE LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_VE',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_TC(self, target, option, names, values):
        """
        CMD_LINE_TC
            : CMD_TOKEN_TC LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_RETURN
            | CMD_TOKEN_TC LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_TC',
            option=option,
            names=names,
            values=values)

    def on_CMD_LINE_KL(self, target, option, names, values):
        """
        CMD_LINE_KL
            : CMD_TOKEN_KL LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_DOUBLE LT_COMMA LT_TEXT_EX LT_COMMA LT_DOUBLE LT_COMMA LT_DOUBLE LT_RETURN
            | CMD_TOKEN_KL LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_INTVAL LT_COMMA LT_TEXT_EX LT_COMMA LT_DOUBLE LT_COMMA LT_DOUBLE LT_RETURN
            | CMD_TOKEN_KL LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_DOUBLE LT_COMMA LT_DOUBLE LT_RETURN
            | CMD_TOKEN_KL LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_DOUBLE LT_COMMA LT_TEXT_EX LT_COMMA LT_POS_ERR LT_COMMA LT_POS_ERR LT_RETURN
            | CMD_TOKEN_KL LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_INTVAL LT_COMMA LT_TEXT_EX LT_COMMA LT_POS_ERR LT_COMMA LT_POS_ERR LT_RETURN
            | CMD_TOKEN_KL LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_TEXT_EX LT_COMMA LT_POS_ERR LT_COMMA LT_POS_ERR LT_RETURN
        """
        return self.defaultNodeClass(
            target='CMD_LINE_KL',
            option=option,
            names=names,
            values=values)

    def on_LT_TEXT_EX(self, target, option, names, values):
        """
        LT_TEXT_EX
            : LT_TEXT
            | LT_NUMERIC
            | LT_OKNG
        """
        return self.defaultNodeClass(
            target='LT_TEXT_EX',
            option=option,
            names=names,
            values=values)

    def on_LT_NUMERIC(self, target, option, names, values):
        """
        LT_NUMERIC
            : LT_INTVAL
            | LT_HEX
        """
        return self.defaultNodeClass(
            target='LT_NUMERIC',
            option=option,
            names=names,
            values=values)

    def on_LT_INTVAL(self, target, option, names, values):
        """
        LT_INTVAL
            : LT_INTEGER
            | LT_INT2
            | LT_INT10
        """
        return self.defaultNodeClass(
            target='LT_INTVAL',
            option=option,
            names=names,
            values=values)

    # -----------------------------------------
    # raw lex script, verbatim here
    # -----------------------------------------
    lexscript = r"""











%x	COMMAND PARAM TEXTPARAM TEXTPARAM2
%{
#include <stdlib.h>
#include "itsh.tab.h"
#include "merit_bat.h"

#ifdef YYDEBUG
extern int yydebug;
#endif
extern int alloc_count;
static char body_line[BODY_LINE_MAX_LEN+1];
extern char cmd_line[BODY_LINE_MAX_LEN+1];

extern char *itc_strdup(const char *s);
extern CMD_POS_PARAM    G_CMD_POS_PARAM;

void to_command();

%}

lt_comma		(,)
lt_integer		([-\+]?[0-9]+)
lt_double		([-\+]?[0-9]+\.[0-9]+)
lt_pos_err		([-\+]?[X]+\.[X]+)
lt_okng			(OK|NG)
lt_on			(ON)
lt_off			(OF)
lt_ip_addr		([0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3})
lt_return		(\n)
lt_return_2		([\r\n])
lt_hex			([0-9A-Fa-f]+)
lt_xx			^([A-Za-z][0-9A-Za-z])

lt_x1			^(([X]{1}[ABCDEFGHJKMNPQRSTUVWYZ]{1})|([Y]{1}[ABEFGHIJKQRSTUVWC]{1})|(HP))
lt_int2			([0-9]{2})
lt_int10		([0-9]{10})



%%

<PARAM>{lt_comma}	return LT_COMMA;
<TEXTPARAM>{lt_comma}	return LT_COMMA;


<PARAM>{lt_int2} {
	yylval.strval = itc_strdup(yytext);
	#ifdef DEBUG
	printf("[%s][Line:%04d]q(^-^)qlt_int2[%s]\n",__FUNCTION__,__LINE__,yytext);
	#endif
	return (LT_INT2);
};

<PARAM>{lt_int2}/{lt_okng}{lt_return} {
	yylval.strval = itc_strdup(yytext);
	#ifdef DEBUG
	printf("[%s][Line:%04d]q(^-^)qlt_int2[%s]\n",__FUNCTION__,__LINE__,yytext);
	#endif
	return (LT_INT2);
};

<PARAM>{lt_int10} {
	yylval.strval = itc_strdup(yytext);
	#ifdef DEBUG
	printf("[%s][Line:%04d]q(^-^)qlt_int10[%s]\n",__FUNCTION__,__LINE__,yytext);
	#endif
	return (LT_INT10);
};

<PARAM>{lt_int10}/{lt_okng}{lt_return} {
	yylval.strval = itc_strdup(yytext);
	#ifdef DEBUG
	printf("[%s][Line:%04d]q(^-^)qlt_int10[%s]\n",__FUNCTION__,__LINE__,yytext);
	#endif
	return (LT_INT10);
};

<PARAM>{lt_integer} {
	yylval.strval = itc_strdup(yytext);
	#ifdef DEBUG
	printf("[%s][Line:%04d]q(^-^)qlt_integer[%s]\n",__FUNCTION__,__LINE__,yytext);
	#endif
	return (LT_INTEGER);
};

<PARAM>{lt_integer}/{lt_okng}{lt_return} {
	yylval.strval = itc_strdup(yytext);
	#ifdef DEBUG
	printf("[%s][Line:%04d]q(^-^)qlt_integer[%s]\n",__FUNCTION__,__LINE__,yytext);
	#endif
	return (LT_INTEGER);
};

<PARAM>{lt_hex}	{
	yylval.strval = itc_strdup(yytext);
	#ifdef DEBUG
	printf("[%s][Line:%04d]q(^-^)qlt_hex[%s]\n",__FUNCTION__,__LINE__,yytext);
	#endif
	return LT_HEX;
};

<PARAM>{lt_double} {
	yylval.strval = itc_strdup(yytext);
	#ifdef DEBUG
	printf("[%s][Line:%04d]q(^-^)qlt_double[%s]\n",__FUNCTION__,__LINE__,yytext);
	#endif
	return(LT_DOUBLE);
};

<PARAM>{lt_double}/{lt_okng}{lt_return} {
	yylval.strval = itc_strdup(yytext);
	#ifdef DEBUG
	printf("[%s][Line:%04d]q(^-^)qlt_double[%s]\n",__FUNCTION__,__LINE__,yytext);
	#endif
	return(LT_DOUBLE);
};

<PARAM>{lt_pos_err}	{
	yylval.strval = itc_strdup(yytext);
	#ifdef DEBUG
	printf("[%s][Line:%04d]q(^-^)qlt_pos_err[%s]\n",__FUNCTION__,__LINE__,yytext);
	#endif
	return LT_POS_ERR;
};

<PARAM>{lt_okng}	{
	yylval.strval = itc_strdup(yytext);
	#ifdef DEBUG
	printf("[%s][Line:%04d]q(^-^)qlt_okng[%s]\n",__FUNCTION__,__LINE__,yytext);
	#endif
	return LT_OKNG;
};

<PARAM>{lt_on}	{
	yylval.strval = itc_strdup(yytext);
	#ifdef DEBUG
	printf("[%s][Line:%04d]q(^-^)qlt_on[%s]\n",__FUNCTION__,__LINE__,yytext);
	#endif
	return LT_ON;
};

<PARAM>{lt_off}	{
	yylval.strval = itc_strdup(yytext);
	#ifdef DEBUG
	printf("[%s][Line:%04d]q(^-^)qlt_off[%s]\n",__FUNCTION__,__LINE__,yytext);
	#endif
	return LT_OFF;
};

<PARAM>{lt_ip_addr}	{
	yylval.strval = itc_strdup(yytext);
	#ifdef DEBUG
	printf("[%s][Line:%04d]q(^-^)qlt_ip_addr[%s]\n",__FUNCTION__,__LINE__,yytext);
	#endif
	return LT_IP_ADDR;
};

<TEXTPARAM>([^,\n]+)/{lt_return}	{
	yylval.strval = itc_strdup(yytext);
	#ifdef DEBUG
	printf("[%s][Line:%04d]q(^-^)q([^,\\n]+)/(\\n)[%s]\n",__FUNCTION__,__LINE__,yytext);
	#endif
	return LT_TEXT;
};

<TEXTPARAM2>([^\n]+)/{lt_return}	{
	yylval.strval = itc_strdup(yytext);
	#ifdef DEBUG
	printf("[%s][Line:%04d]q(^-^)q([^\\n]+)/(\\n)[%s]\n",__FUNCTION__,__LINE__,yytext);
	#endif
	return LT_TEXT;
};

<PARAM>([^,\n\r]+)	{
	yylval.strval = itc_strdup(yytext);
	#ifdef DEBUG
	printf("[%s][Line:%04d]q(^-^)q([^,\\n]+)[%s]\n",__FUNCTION__,__LINE__,yytext);
	#endif
	return LT_TEXT;
};

<COMMAND>(.+){lt_return}	{
	memset(body_line,0x00,sizeof(body_line));
	strncpy(body_line,yytext,strlen(yytext));
	REJECT;
};

<COMMAND>^[\t ]*{lt_return}		;

<COMMAND>P	{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/P\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_P;
};

<COMMAND>^H												{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/H\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_H;
};

<COMMAND>^SC												{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/SC\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_SC;
};

<COMMAND>^SA														{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/SA0\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_SA;
};

<COMMAND>^BT															{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/BT0\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_BT;
};

<COMMAND>^A														{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/A\n",__FUNCTION__,__LINE__);
	#endif

	return CMD_TOKEN_A;
};

<COMMAND>^EG															{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/EG\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_EG;
};

<COMMAND>^AM									{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/AM\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_AM;
};

<COMMAND>^AMOF									{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/AM\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_AMOF;
};

<COMMAND>^AMON									{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/AM\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_AMON;
};

<COMMAND>^CL		{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/CL\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_CL;
};
<COMMAND>^CM0															{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/CM0\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_CM0;
};
<COMMAND>^CM1															{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/CM0\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_CM1;
};
<COMMAND>^D0															{
	strcpy(cmd_line,body_line);
	BEGIN (TEXTPARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><TEXTPARAM>(= _ =)/D0\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_D0;
};
<COMMAND>^D1															{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/D1\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_D1;
};
<COMMAND>^D2															{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/D2\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_D2;
};
<COMMAND>^D3															{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/D3\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_D3;
};
<COMMAND>^M0														{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/M0\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_M0;
};
<COMMAND>^M1															{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/M1\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_M1;
};
<COMMAND>^M2															{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/M2\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_M2;
};
<COMMAND>^M3															{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/M3\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_M3;
};
<COMMAND>^M4															{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/M4\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_M4;
};
<COMMAND>^M5															{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/M5\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_M5;
};
<COMMAND>^M6															{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/M6\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_M6;
};
<COMMAND>^M7															{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/M7\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_M7;
};
<COMMAND>^M8															{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/M8\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_M8;
};

<COMMAND>^T																		{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/T\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_T;
};
<COMMAND>^P																		{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/P\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_P;
};
<COMMAND>^I																		{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/I\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_I;
};
<COMMAND>^R																	{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/R\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_R;
};
<COMMAND>^C																		{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/C\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_C;
};
<COMMAND>^N																		{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/N\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_N;
};
<COMMAND>^F																	{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/F\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_F;
};
<COMMAND>^W																		{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/W\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_W;
};
<COMMAND>^U																		{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/U\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_U;
};
<COMMAND>^J																	{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/J\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_J;
};
<COMMAND>^EC																		{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/EC\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_EC;
};
<COMMAND>^FC																		{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/FC\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_FC;
};
<COMMAND>^HC																		{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/HC\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_HC;
};
<COMMAND>^LC																		{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/LC\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_LC;
};
<COMMAND>^OV																		{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/OV\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_OV;
};
<COMMAND>^FT																		{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/FT\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_FT;
};
<COMMAND>^FS																		{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/FS\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_FS;
};

<COMMAND>^HS										{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/HS\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_HS;
};

<COMMAND>^HE										{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/HE\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_HE;
};

<COMMAND>^HF										{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/HF\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_HF;
};

<COMMAND>^HH										{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/HH\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_HH;
};

<COMMAND>^HL										{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/HL\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_HL;
};

<COMMAND>^AH:										{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/AH\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_AH;
};

<COMMAND>^PN										{
	strcpy(cmd_line,body_line);
	BEGIN (TEXTPARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><TEXTPARAM>(= _ =)/PN\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_PN;
};

<COMMAND>^VR										{
	strcpy(cmd_line,body_line);
	BEGIN (TEXTPARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><TEXTPARAM>(= _ =)/VR\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_VR;
};

<COMMAND>^SD										{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/SD\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_SD_1;
};

<COMMAND>^SD/([0-9]{4})(.*){lt_return}										{
	BEGIN (TEXTPARAM);
	#ifdef DEBUG

	printf("[%s][Line:%04d]-><TEXTPARAM>(= _ =)/SD(DIAGNOSIS)\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_SD_2;
};

<COMMAND>^NP/{lt_integer},{lt_integer}{lt_return}				{


	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/NENPI\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_NENPI;
};

<COMMAND>^V				{
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/V\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_V;
};

<COMMAND>^EA				{
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/EA\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_EA;
};

<COMMAND>^PA				{
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/PA\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_PA;
};

<COMMAND>^PB				{
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/PB\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_PB;
};

<COMMAND>^PC				{
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/PC\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_PC;
};

<COMMAND>^UA				{
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/UA\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_UA;
};

<COMMAND>^UB				{
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/UB\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_UB;
};

<COMMAND>^SW				{
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/SW\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_SW;
};

<COMMAND>^ST				{
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/ST\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_ST;
};

<COMMAND>^MC				{
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/MC\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_MC;
};

<COMMAND>^MT				{
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/MT\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_MT;
};

<COMMAND>^DA				{
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/DA\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_DA;
};

<COMMAND>^SL				{
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/SL\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_SL;
};

<COMMAND>^TD				{
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/TD\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_TD;
};


<COMMAND>^AE/{lt_integer}{lt_comma}{lt_integer}{lt_return}				{
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/AE\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_AE;
};

<COMMAND>^AE				{
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/AE\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_AE;
};


<COMMAND>^AR/{lt_integer}{lt_comma}{lt_integer}{lt_return}				{
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/AR\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_AR;
};


<COMMAND>^AR				{
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/AR\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_AR;
};


<COMMAND>^RR/{lt_integer}{lt_comma}{lt_integer}{lt_return}				{
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/RR\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_RR;
};


<COMMAND>^RR				{
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/RR\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_RR;
};


<COMMAND>^SSID				{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/SSID\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_SSID;
};


<COMMAND>^KL				{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/KL\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_KL;
};



<COMMAND>{lt_x1}/{lt_integer}{lt_return}			{


	if(0x00 == G_CMD_POS_PARAM.cmd_all[0]){
		#ifdef DEBUG
		printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 1(REJECT))\n",__FUNCTION__,__LINE__);
		#endif
		REJECT;
	}

	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 1)\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_X1;
}


<COMMAND>{lt_x1}/{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_return}			{


	if(0x00 == G_CMD_POS_PARAM.cmd_all[0]){
		#ifdef DEBUG
		printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 4(REJECT))\n",__FUNCTION__,__LINE__);
		#endif
		REJECT;
	}

	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 4)\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_X1;
}


<COMMAND>{lt_x1}/{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_return}			{


	if(0x00 == G_CMD_POS_PARAM.cmd_all[0]){
		#ifdef DEBUG
		printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 3(REJECT))\n",__FUNCTION__,__LINE__);
		#endif
		REJECT;
	}

	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 3)\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_X1;
}



<COMMAND>{lt_x1}/{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_return}			{


	if(0x00 == G_CMD_POS_PARAM.cmd_all[0]){
		#ifdef DEBUG
		printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 5(REJECT))\n",__FUNCTION__,__LINE__);
		#endif
		REJECT;
	}

	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 5)\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_X1;
}


<COMMAND>{lt_x1}/{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_return}			{


	if(0x00 == G_CMD_POS_PARAM.cmd_all[0]){
		#ifdef DEBUG
		printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 12(REJECT))\n",__FUNCTION__,__LINE__);
		#endif
		REJECT;
	}

	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 12)\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_X1;
}


<COMMAND>{lt_x1}/{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_return}			{


	if(0x00 == G_CMD_POS_PARAM.cmd_all[0]){
		#ifdef DEBUG
		printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 13(REJECT))\n",__FUNCTION__,__LINE__);
		#endif
		REJECT;
	}

	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 13)\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_X1;
}


<COMMAND>{lt_x1}/{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_return}			{


	if(0x00 == G_CMD_POS_PARAM.cmd_all[0]){
		#ifdef DEBUG
		printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 26(REJECT))\n",__FUNCTION__,__LINE__);
		#endif
		REJECT;
	}

	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 26)\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_X1;
}


<COMMAND>{lt_x1}/{lt_integer}{lt_comma}{lt_integer}{lt_return}			{


	if(0x00 == G_CMD_POS_PARAM.cmd_all[0]){
		#ifdef DEBUG
		printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 2(REJECT))\n",__FUNCTION__,__LINE__);
		#endif
		REJECT;
	}
	
	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 2)\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_X1;
}


<COMMAND>{lt_x1}/{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_return}			{


	if(0x00 == G_CMD_POS_PARAM.cmd_all[0]){
		#ifdef DEBUG
		printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 17(REJECT))\n",__FUNCTION__,__LINE__);
		#endif
		REJECT;
	}

	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 17)\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_X1;
}


<COMMAND>{lt_x1}/{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_return}			{


	if(0x00 == G_CMD_POS_PARAM.cmd_all[0]){
		#ifdef DEBUG
		printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 11(REJECT))\n",__FUNCTION__,__LINE__);
		#endif
		REJECT;
	}

	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 11)\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_X1;
}



<COMMAND>{lt_x1}/{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_return}			{


	if(0x00 == G_CMD_POS_PARAM.cmd_all[0]){
		#ifdef DEBUG
		printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 6(REJECT))\n",__FUNCTION__,__LINE__);
		#endif
		REJECT;
	}

	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 6)\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_X1;
}


<COMMAND>{lt_x1}/{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_return}			{


	if(0x00 == G_CMD_POS_PARAM.cmd_all[0]){
		#ifdef DEBUG
		printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 8(REJECT))\n",__FUNCTION__,__LINE__);
		#endif
		REJECT;
	}

	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 8)\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_X1;
}


<COMMAND>^HA				{
	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);

	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/HA\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_HA;
};

<COMMAND>^LK				{
	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);

	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/LK\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_LK;
};

<COMMAND>^YD				{
	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);

	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/YD\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_YD;
};

<COMMAND>^OT				{
	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);

	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/OT\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_OT;
};

<COMMAND>^M/{lt_integer}{lt_return}				{
	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);



	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/M\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_M;
};

<COMMAND>^JH				{
	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);

	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/JH\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_JH;
};

<COMMAND>^JS				{
	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);

	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/JS\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_JS;
};

<COMMAND>^JE				{
	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);

	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/JE\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_JE;
};

<COMMAND>^AB				{
	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);

	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/AB\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_AB;
};

<COMMAND>^SS				{
	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);

	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/SS\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_SS;
};

<COMMAND>^SR				{
	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);

	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/SR\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_SR;
};

<COMMAND>^SG				{
	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);

	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/SG\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_SG;
};

<COMMAND>^SU				{
	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);

	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/SU\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_SU;
};

<COMMAND>^DG				{
	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);

	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/DG\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_DG;
};

<COMMAND>^DU				{
	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);

	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/DU\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_DU;
};

<COMMAND>^DC				{
	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);

	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/DC\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_DC;
};

<COMMAND>^DR				{
	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);

	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/DR\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_DR;
};

<COMMAND>^\*\*	{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/Asterisk1\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_ASTRSK1;
};

<COMMAND>^\*	{
	strcpy(cmd_line,body_line);
	BEGIN (TEXTPARAM2);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><TEXTPARAM2>(= _ =)/Asterisk2\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_ASTRSK2;
};

<COMMAND>^#	{
	strcpy(cmd_line,body_line);
	BEGIN (TEXTPARAM2);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><TEXTPARAM2>(= _ =)/NUMSIGN\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_NUMSIGN;
};


<COMMAND>^FD/([^\r\n]+){lt_return}	{
	yylval.strval = itc_strdup(yytext);

	strcpy(cmd_line,body_line);
	BEGIN (TEXTPARAM2);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><TEXTPARAM2>(= _ =)/FD\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_FD;
};


<COMMAND>^FR/([^\r\n]+){lt_return}	{
	yylval.strval = itc_strdup(yytext);

	strcpy(cmd_line,body_line);
	BEGIN (TEXTPARAM2);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><TEXTPARAM2>(= _ =)/FR\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_FR;
};


<COMMAND>^FQ/([^\r\n]+){lt_return}	{
	yylval.strval = itc_strdup(yytext);

	strcpy(cmd_line,body_line);
	BEGIN (TEXTPARAM2);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><TEXTPARAM2>(= _ =)/FR\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_FQ;
};





<COMMAND>^HD/{lt_okng}{lt_return}	{
	yylval.strval = itc_strdup(yytext);

	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><TEXTPARAM2>(= _ =)/HD\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_HD;
};


<COMMAND>^HP/([^\r\n]+){lt_return}	{
	yylval.strval = itc_strdup(yytext);

	strcpy(cmd_line,body_line);
	BEGIN (TEXTPARAM2);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><TEXTPARAM2>(= _ =)/HP\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_HP;
};


<COMMAND>^HQ/([^\r\n]+){lt_return}	{
	yylval.strval = itc_strdup(yytext);

	strcpy(cmd_line,body_line);
	BEGIN (TEXTPARAM2);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><TEXTPARAM2>(= _ =)/HQ\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_HQ;
};


<COMMAND>^VE/([^\r\n,]+){lt_comma}([^\r\n,]+){lt_comma}([^\r\n,]+){lt_comma}([^\r\n,]+){lt_return}	{
	yylval.strval = itc_strdup(yytext);

	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><TEXTPARAM2>(= _ =)/VE\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_VE;
};


<COMMAND>^TC/([^\r\n,]+){lt_comma}([^\r\n,]+){lt_comma}([^\r\n,]+){lt_comma}([^\r\n,]+){lt_comma}([^\r\n,]+){lt_comma}([^\r\n,]+){lt_comma}([^\r\n,]+){lt_comma}([^\r\n,]+){lt_comma}([^\r\n,]+){lt_comma}([^\r\n,]+){lt_comma}([^\r\n,]+){lt_comma}([^\r\n,]+){lt_return}	{
	yylval.strval = itc_strdup(yytext);

	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><TEXTPARAM2>(= _ =)/TC(12)\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_TC;
};


<COMMAND>^TC/([^\r\n,]+){lt_comma}([^\r\n,]+){lt_comma}([^\r\n,]+){lt_comma}([^\r\n,]+){lt_comma}([^\r\n,]+){lt_comma}([^\r\n,]+){lt_comma}([^\r\n,]+){lt_comma}([^\r\n,]+){lt_comma}([^\r\n,]+){lt_comma}([^\r\n,]+){lt_return}	{
	yylval.strval = itc_strdup(yytext);

	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><TEXTPARAM2>(= _ =)/TC(10)\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_TC;
};





<PARAM>{lt_return}	{
	#ifdef DEBUG
	printf("[%s][Line:%04d](PARAM)-(LT_RETURN)\n",__FUNCTION__,__LINE__);
	#endif
	return LT_RETURN;
};

<PARAM>{lt_return_2}	{
	#ifdef DEBUG
	printf("[%s][Line:%04d](PARAM)-(LT_RETURN_2)\n",__FUNCTION__,__LINE__);
	#endif
	return LT_RETURN_2;
};


<TEXTPARAM>{lt_return}	{
	#ifdef DEBUG
	printf("[%s][Line:%04d](TEXTPARAM)-(LT_RETURN)\n",__FUNCTION__,__LINE__);
	#endif
	return LT_RETURN;
};

<TEXTPARAM2>{lt_return}	{
	#ifdef DEBUG
	printf("[%s][Line:%04d](TEXTPARAM2)-(LT_RETURN)\n",__FUNCTION__,__LINE__);
	#endif
	return LT_RETURN;
};


<INITIAL>(.+){lt_return}	{
	#ifdef DEBUG
	printf("[%s][Line:%04d](...mail head...)\n",__FUNCTION__,__LINE__);
	#endif
	return LT_HEADER_ONE_LINE;
};

<INITIAL>{lt_return}	{
	to_command();
	return LT_RETURN_HEADER;
}

<*><<EOF>>	{
	_eof();
	yyterminate();
}

<COMMAND>{lt_xx}/([1|0|\*]),{lt_integer}{lt_return}			{

	if(0x00 != G_CMD_POS_PARAM.cmd_all[0]){
		#ifdef DEBUG
	
		printf("[%s][Line:%04d]-><PARAM>(= _ =)/XX(SELF-01)\n",__FUNCTION__,__LINE__);
		#endif
		REJECT;
	}

	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	
	#ifdef DEBUG

	printf("[%s][Line:%04d]-><PARAM>(= _ =)/XX(SELF-02)\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_XX;
}

<COMMAND>{lt_xx}/([1|0|\*]),([^,\n]+),{lt_int10}{lt_return}			{

	if(0x00 != G_CMD_POS_PARAM.cmd_all[0]){
		#ifdef DEBUG
	
		printf("[%s][Line:%04d]-><PARAM>(= _ =)/XX_V7(SELF-03)\n",__FUNCTION__,__LINE__);
		#endif
		REJECT;
	}

	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	
	#ifdef DEBUG

	printf("[%s][Line:%04d]-><PARAM>(= _ =)/XX_V7(SELF-04)\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_XX;
}


<COMMAND>{lt_xx}/([1|0|\*]),([^,\n]+),{lt_int10},([^,\n]+){lt_return}			{

	if(0x00 != G_CMD_POS_PARAM.cmd_all[0]){
		#ifdef DEBUG
	
		printf("[%s][Line:%04d]-><PARAM>(= _ =)/XX_V7(SELF-05)\n",__FUNCTION__,__LINE__);
		#endif
		REJECT;
	}

	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	
	#ifdef DEBUG

	printf("[%s][Line:%04d]-><PARAM>(= _ =)/XX_V7(SELF-06)\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_XX;
}
<*>(.)	{




	#ifdef DEBUG
	printf("[%s][Line:%04d]TOKEN_ERROR\n",__FUNCTION__,__LINE__);
	#endif
	return TOKEN_ERROR;
};


%%

int yywrap(void)
{
	#ifdef YYDEBUG
	yydebug = 1;
	#endif
	BEGIN (INITIAL);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><INITIAL>\n",__FUNCTION__,__LINE__);
	#endif
	return 1;
}

void to_command()
{
	BEGIN (COMMAND);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><COMMAND> **************************************** COMMAND\n",__FUNCTION__,__LINE__);
	#endif
}

void next_cmd()
{
	to_command();
	#ifdef DEBUG
	printf("[%s][Line:%04d]<< 1 Line = 1 command OK>>\n",__FUNCTION__,__LINE__);
	printf("\n");
	#endif
}

void setInitial_mode()
{
	BEGIN (INITIAL);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><INITIAL> **************************************** INITIAL\n",__FUNCTION__,__LINE__);
	#endif
}


    """
    # -----------------------------------------
    # end raw lex script
    # -----------------------------------------


def usage():
    print('%s: PyBison parser derived from %s and %s' % (sys.argv[0], bisonFile, lexFile))
    print('Usage: %s [-k] [-v] [-d] [filename]' % sys.argv[0])
    print('  -k       Keep temporary files used in building parse engine lib')
    print('  -v       Enable verbose messages while parser is running')
    print('  -d       Enable garrulous debug messages from parser engine')
    print('  filename path of a file to parse, defaults to stdin')


def main(*args):
    """
    Unit-testing func
    """

    keepfiles = 0
    verbose = 0
    debug = 0
    filename = None
    args = list(args)
    for s in ['-h', '-help', '--h', '--help', '-?']:
        if s in args:
            usage()
            sys.exit(0)

    if len(args) > 0:
        if '-k' in args:
            keepfiles = 1
            args.remove('-k')
        if '-v' in args:
            verbose = 1
            args.remove('-v')
        if '-d' in args:
            debug = 1
            args.remove('-d')
    if len(args) > 0:
        filename = args[0]

    p = Parser(verbose=verbose, keepfiles=keepfiles)
    tree = p.run(file=filename, debug=debug)
    return tree


if __name__ == '__main__':
    main(*(sys.argv[1:]))

