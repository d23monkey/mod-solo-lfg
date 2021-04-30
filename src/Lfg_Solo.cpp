/*
** Made by Traesh https://github.com/Traesh
** AzerothCore 2019 http://www.azerothcore.org/
** Conan513 https://github.com/conan513
** Made into a module by Micrah https://github.com/milestorme/
*/

#include "ScriptMgr.h"
#include "Player.h"
#include "Config.h"
#include "World.h"
#include "LFGMgr.h"
#include "Chat.h"
#include "Opcodes.h"

class SoloLfg_Player : public PlayerScript
{
public:
    SoloLfg_Player() : PlayerScript("SoloLfg_Player") { }

    void OnLogin(Player* /*player*/) override
    {
        if (!sConfigMgr->GetOption<bool>("SoloLFG.Enable", false))
            return;

        if (!sLFGMgr->IsSoloLFG())
            sLFGMgr->ToggleSoloLFG();
    }
};

void AddLfgSoloScripts()
{
    new SoloLfg_Player();
}
