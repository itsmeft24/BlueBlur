#pragma once

#include <Hedgehog/Base/Container/hhMap.h>
#include <Hedgehog/Base/Thread/hhSynchronizedObject.h>

namespace Hedgehog::Base
{
    class CSharedString;
}

namespace Hedgehog::Universe
{
    class CMessageActor;

    class CMessageManager : public Hedgehog::Base::CSynchronizedObject
    {
    public:
        hh::map<size_t, CMessageActor*> m_MessageActorMap;
        hh::map<Hedgehog::Base::CSharedString, hh::list<CMessageActor*>> m_CategoryMap;

        CMessageActor* GetMessageActor(size_t in_ActorID) const;
        bool AddMessageActor(const Hedgehog::Base::CSharedString& in_rCategory, CMessageActor* in_pMessageActor);
    };

    BB_ASSERT_OFFSETOF(CMessageManager, m_MessageActorMap, 0x4);
    BB_ASSERT_OFFSETOF(CMessageManager, m_CategoryMap, 0x10);
}

#include <Hedgehog/Universe/Engine/hhMessageManager.inl>