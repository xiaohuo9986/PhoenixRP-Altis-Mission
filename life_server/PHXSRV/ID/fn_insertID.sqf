/*
	@File: fn_insertID.sqf
	@Author: Jack "Scarso" Farhall
	@Description: Creates ourseleves a new ID Card...
*/
if !(params [
	["_uid", "", [""]],
	["_id", [], [[]]],
	["_unit", objNull, [objNull]]
]) exitWith {};

if !(canSuspend) exitWith {_this spawn PHXSRV_fnc_insertID};

[_uid] call PHXSRV_fnc_wipeID; // Set all current IDS under our steam id to inactive...

// Make all values database friendly...
_id set[1, ([(_id select 1)] call DB_fnc_mresString)];
if ((_id select 5) isEqualType false) then { _id set[5, ([(_id select 5), 0] call DB_fnc_bool)] };

// Insert it into the database...
[format["INSERT INTO phxids (playerid, uid, realname, age, gender, ethnicity, isFake, active) VALUES ('%1', '%2', '%3', '%4', '%5', '%6', '%7', '1')",
	_uid, // Steam ID...
	_id select 0, // UID...
	_id select 1, // Realname...
	_id select 2, // Age...
	_id select 3, // Gender...
	_id select 4, // Ethnicity...
	_id select 5 // isFake...
], 1] call DB_fnc_asyncCall;

uiSleep 0.35;

private _id = ["SELECT MAX(ID) FROM PHXids", 2] call DB_fnc_asyncCall;

// Update the ID for the ID Card on our client...
[format["UPDATE phxclients SET cardID='%1' WHERE playerid ='%2' LIMIT 1",
	(_id select 0),
	_uid
],1] call DB_fnc_asyncCall;