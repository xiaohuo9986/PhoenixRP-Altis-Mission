class RscItemMenu {
	idd = 8000;
	name = "RscItemMenu";
  	onLoad = "";

    class ControlsBackground {
        class Background : Life_RscBackground {
            idc = -1;
            colorBackground[] = {0.16,0.16,0.16,1};
			x = safeZoneX + safeZoneW * 0.460625;
			y = safeZoneY + safeZoneH * 0.35111112;
			w = safeZoneW * 0.13125;
			h = safeZoneH * 0.31777778;
        };

        class PageTitle : Life_RscText {
            idc = 8001;
            text = "Give Items";
			x = safeZoneX + safeZoneW * 0.460625;
			y = safeZoneY + safeZoneH * 0.33;
			w = safeZoneW * 0.13125;
			h = safeZoneH * 0.02222223;
			colorBackground[] = {0.102,0.102,0.102,1};
			colorText[] = {1,1,1,1};
			font = "RobotoCondensedLight";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 30) * 1);
        };
    };

    class Controls {
		class CloseButton : Life_RscButtonMenuIcon {
			idc = -1;
			x = safeZoneX + safeZoneW * 0.575625;
			y = safeZoneY + safeZoneH * 0.33;
			w = safeZoneW * 0.01625;
			h = safeZoneH * 0.02222223;
            style = ST_KEEP_ASPECT_RATIO + ST_CENTER + ST_PICTURE;
            text = "\a3\3DEN\Data\Displays\Display3DEN\search_end_ca.paa";
            onButtonClick = "closeDialog 0;";
            colorBackground[] = {0,0,0,1};
            colorFocused[] = {0.09,0.09,0.09,1};
            colorBackgroundActive[] = {0.03,0.03,0.03,1};
            sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
		};

        class ListBox : Life_RscListBox {
            idc = 8004;
			x = safeZoneX + safeZoneW * 0.46375;
			y = safeZoneY + safeZoneH * 0.35666667;
			w = safeZoneW * 0.125625;
			h = safeZoneH * 0.25777778;
            color[] = {0.09,0.09,0.09,1};
			colorBackground[] = {0.09,0.09,0.09,1};
			colorText[] = {1,1,1,1};
			font = "RobotoCondensedLight";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 30) * 1);
			rowHeight = 0;
			soundSelect[] = {"\A3\ui_f\data\sound\RscListbox\soundSelect",0.09,1.0};
        };

		class ValueEdit:Life_RscEdit {
			idc = 8002;
			x = safeZoneX + safeZoneW * 0.46375;
			y = safeZoneY + safeZoneH * 0.61777778;
			w = safeZoneW * 0.125625;
			h = safeZoneH * 0.02222223;
            text = "1";
			colorBackground[] = {0,0,0,1};
			colorText[] = {1,1,1,1};
		};

        class SubmitButton:Life_RscButton{
			idc = 8003;
			x = safeZoneX + safeZoneW * 0.46375;
			y = safeZoneY + safeZoneH * 0.64333334;
			w = safeZoneW * 0.125625;
			h = safeZoneH * 0.02222223;
			style = 2;
			text = "GIVE";
			onButtonClick = "[""Give""] call life_fnc_giveItem";
			colorBackground[] = {0,0,0,1};
			colorText[] = {1,1,1,1};
            colorBackgroundDisabled[] = {0.05,0.05,0.05,0.8};
			font = "PuristaLight";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 30) * 1);
		};
    };
};