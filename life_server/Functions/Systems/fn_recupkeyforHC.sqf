/*
    File: fn_recupKeyForHC.sqf
    Author : NiiRoZz

    Description:
    Tells the server to recup the Key of player
*/
#include "\life_server\script_macros.hpp"
params [
    ["_uid", "", [""]],
    ["_side", sideUnknown, [civilian]]
];

if (_uid isEqualTo "") exitWith {}; //NULL

_keyArr = missionNamespace getVariable [format ["%1_KEYS_%2",_uid,_side],[]];
[_keyArr] remoteExecCall ["HC_fnc_receivekeyofServer",HC_Life];