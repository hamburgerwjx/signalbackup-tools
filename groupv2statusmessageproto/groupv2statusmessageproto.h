/*
  Copyright (C) 2021-2023  Selwin van Dijk

  This file is part of signalbackup-tools.

  signalbackup-tools is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  signalbackup-tools is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with signalbackup-tools.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef GROUPV2STATUSMESSAGEPROTO_H_
#define GROUPV2STATUSMESSAGEPROTO_H_

#include "../protobufparser/protobufparser.h"

/*
 * For GroupV2 status messages
 *
 * /Signal-Android/libsignal/service/src/main/proto/Groups.proto
 * /Signal-Android/libsignal/service/src/main/proto/DecryptedGroups.proto
 * /Signal-Android/libsignal/service/src/main/proto/SignalService.proto
 * /Signal-Android/app/src/main/proto/Database.proto
 */


/*
message AccessControl {
  enum AccessRequired {
    UNKNOWN       = 0;
    ANY           = 1;
    MEMBER        = 2;
    ADMINISTRATOR = 3;
    UNSATISFIABLE = 4;
  }

  AccessRequired attributes        = 1;
  AccessRequired members           = 2;
  AccessRequired addFromInviteLink = 3;
}
*/
typedef ProtoBufParser<protobuffer::optional::ENUM, protobuffer::optional::ENUM,
                       protobuffer::optional::ENUM> AccessControl;

/*
message Member {
  enum Role {
    UNKNOWN       = 0;
    DEFAULT       = 1;
    ADMINISTRATOR = 2;
  }

  bytes  userId           = 1;
  Role   role             = 2;
  bytes  profileKey       = 3;
  bytes  presentation     = 4;
  uint32 joinedAtRevision = 5;
}
*/
typedef ProtoBufParser<protobuffer::optional::BYTES, protobuffer::optional::ENUM,
                       protobuffer::optional::BYTES, protobuffer::optional::BYTES,
                       protobuffer::optional::UINT32> Member;

/*
message DecryptedMember {
  bytes       uuid             = 1;
  Member.Role role             = 2;
  bytes       profileKey       = 3;
  uint32      joinedAtRevision = 5;
  bytes       pni              = 6;
}
*/
typedef ProtoBufParser<protobuffer::optional::BYTES, protobuffer::optional::ENUM,
                       protobuffer::optional::BYTES, protobuffer::optional::DUMMY,
                       protobuffer::optional::UINT32, protobuffer::optional::BYTES> DecryptedMember;

/*
message DecryptedPendingMember {
  bytes       uuid           = 1;
  Member.Role role           = 2;
  bytes       addedByUuid    = 3;
  uint64      timestamp      = 4;
  bytes       uuidCipherText = 5;
}
*/
typedef ProtoBufParser<protobuffer::optional::BYTES, protobuffer::optional::ENUM,
                       protobuffer::optional::BYTES, protobuffer::optional::UINT64,
                       protobuffer::optional::BYTES> DecryptedPendingMember;

/*
message DecryptedRequestingMember {
  bytes  uuid       = 1;
  bytes  profileKey = 2;
  uint64 timestamp  = 4;
}
*/
typedef ProtoBufParser<protobuffer::optional::BYTES, protobuffer::optional::BYTES,
                       protobuffer::optional::DUMMY, protobuffer::optional::UINT64> DecryptedRequestingMember;


/*
message DecryptedBannedMember {
  bytes  uuid      = 1;
  uint64 timestamp = 2;
}
*/
typedef ProtoBufParser<protobuffer::optional::BYTES, protobuffer::optional::UINT64> DecryptedBannedMember;


/*
message DecryptedPendingMemberRemoval {
  bytes uuid           = 1;
  bytes uuidCipherText = 2;
}
*/
typedef ProtoBufParser<protobuffer::optional::BYTES,  protobuffer::optional::BYTES> DecryptedPendingMemberRemoval;

/*
message DecryptedApproveMember {
  bytes       uuid = 1;
  Member.Role role = 2;
}
*/
typedef ProtoBufParser<protobuffer::optional::BYTES, protobuffer::optional::ENUM> DecryptedApproveMember;

/*
message DecryptedModifyMemberRole {
  bytes       uuid = 1;
  Member.Role role = 2;
}
*/
typedef ProtoBufParser<protobuffer::optional::BYTES, protobuffer::optional::ENUM> DecryptedModifyMemberRole;

/*
message DecryptedString {
  string value = 1;
}
*/
typedef ProtoBufParser<protobuffer::optional::STRING> DecryptedString;


/*
message DecryptedTimer {
  uint32 duration = 1;
}
*/
typedef ProtoBufParser<protobuffer::optional::UINT32> DecryptedTimer;

/*
message DecryptedGroupChange {
           bytes                         editor                      = 1;
           uint32                        revision                    = 2;
  repeated DecryptedMember               newMembers                  = 3;
  repeated bytes                         deleteMembers               = 4;
  repeated DecryptedModifyMemberRole     modifyMemberRoles           = 5;
  repeated DecryptedMember               modifiedProfileKeys         = 6;
  repeated DecryptedPendingMember        newPendingMembers           = 7;
  repeated DecryptedPendingMemberRemoval deletePendingMembers        = 8;
  repeated DecryptedMember               promotePendingMembers       = 9;
           DecryptedString               newTitle                    = 10;
           DecryptedString               newAvatar                   = 11;
           DecryptedTimer                newTimer                    = 12;
           AccessControl.AccessRequired  newAttributeAccess          = 13;
           AccessControl.AccessRequired  newMemberAccess             = 14;
           AccessControl.AccessRequired  newInviteLinkAccess         = 15;
  repeated DecryptedRequestingMember     newRequestingMembers        = 16;
  repeated bytes                         deleteRequestingMembers     = 17;
  repeated DecryptedApproveMember        promoteRequestingMembers    = 18;
           bytes                         newInviteLinkPassword       = 19;
           DecryptedString               newDescription              = 20;
           EnabledState                  newIsAnnouncementGroup      = 21;
  repeated DecryptedBannedMember         newBannedMembers            = 22;
  repeated DecryptedBannedMember         deleteBannedMembers         = 23;
  repeated DecryptedMember               promotePendingPniAciMembers = 24;
}

enum EnabledState {
  UNKNOWN  = 0;
  ENABLED  = 1;
  DISABLED = 2;
}

*/
typedef ProtoBufParser<protobuffer::optional::BYTES, protobuffer::optional::UINT32,
                       std::vector<DecryptedMember>, protobuffer::repeated::BYTES,
                       std::vector<DecryptedModifyMemberRole>, std::vector<DecryptedMember>,
                       std::vector<DecryptedPendingMember>, std::vector<DecryptedPendingMemberRemoval>,
                       std::vector<DecryptedMember>, DecryptedString,
                       DecryptedString, DecryptedTimer,
                       protobuffer::optional::ENUM, protobuffer::optional::ENUM,
                       protobuffer::optional::ENUM, std::vector<DecryptedRequestingMember>,
                       protobuffer::repeated::BYTES, std::vector<DecryptedApproveMember>,
                       protobuffer::optional::BYTES, DecryptedString, protobuffer::optional::ENUM,
                       std::vector<DecryptedBannedMember>, std::vector<DecryptedBannedMember>,
                       std::vector<DecryptedMember>> DecryptedGroupChange;

/*
message DecryptedGroup {
           string                    title                     = 2;
           string                    avatar                    = 3;
           DecryptedTimer            disappearingMessagesTimer = 4;
           AccessControl             accessControl             = 5;
           uint32                    revision                  = 6;
  repeated DecryptedMember           members                   = 7;
  repeated DecryptedPendingMember    pendingMembers            = 8;
  repeated DecryptedRequestingMember requestingMembers         = 9;
           bytes                     inviteLinkPassword        = 10;
           string                    description               = 11;
           EnabledState              isAnnouncementGroup       = 12;
  repeated DecryptedBannedMember     bannedMembers             = 13;
}

enum EnabledState {
  UNKNOWN  = 0;
  ENABLED  = 1;
  DISABLED = 2;
}

*/
typedef ProtoBufParser<protobuffer::optional::DUMMY, protobuffer::optional::STRING,
                       protobuffer::optional::STRING, DecryptedTimer,
                       AccessControl, protobuffer::optional::UINT32,
                       std::vector<DecryptedMember>, std::vector<DecryptedPendingMember>,
                       std::vector<DecryptedRequestingMember>, protobuffer::optional::BYTES,
                       protobuffer::optional::STRING, protobuffer::optional::ENUM,
                       std::vector<DecryptedBannedMember>> DecryptedGroup;
/* message Member {
     enum Role {
       UNKNOWN       = 0;
       DEFAULT       = 1;
       ADMINISTRATOR = 2;
     }
     bytes  userId           = 1;
     Role   role             = 2;
     bytes  profileKey       = 3;
     bytes  presentation     = 4; // Only set when sending to server
     uint32 joinedAtRevision = 5;
}
*/
typedef ProtoBufParser<protobuffer::optional::BYTES, protobuffer::optional::ENUM,
                       protobuffer::optional::BYTES, protobuffer::optional::BYTES,
                       protobuffer::optional::UINT32> Member;

/* message PendingMember {
     Member member        = 1;
     bytes  addedByUserId = 2;
     uint64 timestamp     = 3;
}
*/
typedef ProtoBufParser<Member, protobuffer::optional::BYTES, protobuffer::optional::UINT64> PendingMember;

/* message RequestingMember {
     bytes  userId       = 1;
     bytes  profileKey   = 2;
     bytes  presentation = 3; // Only set when sending to server
     uint64 timestamp    = 4;
}
*/
typedef ProtoBufParser<protobuffer::optional::BYTES, protobuffer::optional::BYTES,
                       protobuffer::optional::BYTES, protobuffer::optional::UINT64> RequestingMember;

/* message BannedMember {
  bytes  userId    = 1;
  uint64 timestamp = 2;
}
*/
typedef ProtoBufParser<protobuffer::optional::BYTES, protobuffer::optional::UINT64> BannedMember;

/* message AddMemberAction {
     Member added              = 1;
     bool   joinFromInviteLink = 2;
   }
*/
typedef ProtoBufParser<Member, protobuffer::optional::BOOL> AddMemberAction;

/* message DeleteMemberAction {
     bytes deletedUserId = 1;
   }
*/
typedef ProtoBufParser<protobuffer::optional::BYTES> DeleteMemberAction;

/* message ModifyMemberRoleAction {
     bytes       userId = 1;
     Member.Role role   = 2;
   }
*/
typedef ProtoBufParser<protobuffer::optional::BYTES, protobuffer::optional::ENUM> ModifyMemberRoleAction;

/* message ModifyMemberProfileKeyAction {
     bytes presentation = 1; // Only set when sending to server
     bytes user_id      = 2; // Only set when receiving from server
     bytes profile_key  = 3; // Only set when receiving from server
   }
*/
typedef ProtoBufParser<protobuffer::optional::BYTES, protobuffer::optional::BYTES,
                       protobuffer::optional::BYTES> ModifyMemberProfileKeyAction;

/* message AddPendingMemberAction {
     PendingMember added = 1;
   }
*/
typedef ProtoBufParser<PendingMember> AddPendingMemberAction;

/* message DeletePendingMemberAction {
     bytes deletedUserId = 1;
   }
*/
typedef ProtoBufParser<protobuffer::optional::BYTES> DeletePendingMemberAction;

/* message PromotePendingMemberAction {
     bytes presentation = 1; // Only set when sending to server
     bytes user_id      = 2; // Only set when receiving from server
     bytes profile_key  = 3; // Only set when receiving from server
   }
*/
typedef ProtoBufParser<protobuffer::optional::BYTES, protobuffer::optional::BYTES,
                       protobuffer::optional::BYTES> PromotePendingMemberAction;


/* message PromotePendingPniAciMemberProfileKeyAction {
     bytes presentation = 1; // Only set when sending to server
     bytes userId       = 2; // Only set when receiving from server
     bytes pni          = 3; // Only set when receiving from server
     bytes profileKey   = 4; // Only set when receiving from server
   }
*/
typedef ProtoBufParser<protobuffer::optional::BYTES, protobuffer::optional::BYTES,
                       protobuffer::optional::BYTES, protobuffer::optional::BYTES> PromotePendingPniAciMemberProfileKeyAction;

/* message AddRequestingMemberAction {
     RequestingMember added = 1;
   }
*/
typedef ProtoBufParser<RequestingMember> AddRequestingMemberAction;

/* message DeleteRequestingMemberAction {
     bytes deletedUserId = 1;
   }
*/
typedef ProtoBufParser<protobuffer::optional::BYTES> DeleteRequestingMemberAction;

/* message PromoteRequestingMemberAction {
     bytes       userId = 1;
     Member.Role role   = 2;
   }
*/
typedef ProtoBufParser<protobuffer::optional::BYTES, protobuffer::optional::ENUM> PromoteRequestingMemberAction;

/* message AddBannedMemberAction {
     BannedMember added = 1;
   }
*/
typedef ProtoBufParser<BannedMember> AddBannedMemberAction;

/* message DeleteBannedMemberAction {
     bytes deletedUserId = 1;
   }
*/
typedef ProtoBufParser<protobuffer::optional::BYTES> DeleteBannedMemberAction;

/* message ModifyTitleAction {
     bytes title = 1;
   }
*/
typedef ProtoBufParser<protobuffer::optional::BYTES> ModifyTitleAction;

/* message ModifyDescriptionAction {
     bytes description = 1;
  }
*/
typedef ProtoBufParser<protobuffer::optional::BYTES> ModifyDescriptionAction;

/* message ModifyAvatarAction {
     string avatar = 1;
}
*/
typedef ProtoBufParser<protobuffer::optional::STRING> ModifyAvatarAction;

/* message ModifyDisappearingMessagesTimerAction {
     bytes timer = 1;
   }
*/
typedef ProtoBufParser<protobuffer::optional::BYTES> ModifyDisappearingMessagesTimerAction;

/* message ModifyAttributesAccessControlAction {
    AccessControl.AccessRequired attributesAccess = 1;
  }
*/
typedef ProtoBufParser<> ModifyAttributesAccessControlAction;

/* message ModifyMembersAccessControlAction {
     AccessControl.AccessRequired membersAccess = 1;
   }
*/
typedef ProtoBufParser<> ModifyMembersAccessControlAction;

/* message ModifyAddFromInviteLinkAccessControlAction {
     AccessControl.AccessRequired addFromInviteLinkAccess = 1;
   }
*/
typedef ProtoBufParser<> ModifyAddFromInviteLinkAccessControlAction;

/* message ModifyInviteLinkPasswordAction {
     bytes inviteLinkPassword = 1;
   }
*/
typedef ProtoBufParser<protobuffer::optional::BYTES> ModifyInviteLinkPasswordAction;

/* message ModifyAnnouncementsOnlyAction {
     bool announcementsOnly = 1;
   }
*/
typedef ProtoBufParser<protobuffer::optional::BOOL> ModifyAnnouncementsOnlyAction;


/* message Action {
             bytes                                      sourceServiceId                 = 1;
             uint32                                     revision                        = 2;
    repeated AddMemberAction                            addMembers                      = 3;
    repeated DeleteMemberAction                         deleteMembers                   = 4;
    repeated ModifyMemberRoleAction                     modifyMemberRoles               = 5;
    repeated ModifyMemberProfileKeyAction               modifyMemberProfileKeys         = 6;
    repeated AddPendingMemberAction                     addPendingMembers               = 7;
    repeated DeletePendingMemberAction                  deletePendingMembers            = 8;
    repeated PromotePendingMemberAction                 promotePendingMembers           = 9;
             ModifyTitleAction                          modifyTitle                     = 10;
             ModifyAvatarAction                         modifyAvatar                    = 11;
             ModifyDisappearingMessagesTimerAction      modifyDisappearingMessagesTimer = 12;
             ModifyAttributesAccessControlAction        modifyAttributesAccess          = 13;
             ModifyMembersAccessControlAction           modifyMemberAccess              = 14;
             ModifyAddFromInviteLinkAccessControlAction modifyAddFromInviteLinkAccess   = 15;
    repeated AddRequestingMemberAction                  addRequestingMembers            = 16;
    repeated DeleteRequestingMemberAction               deleteRequestingMembers         = 17;
    repeated PromoteRequestingMemberAction              promoteRequestingMembers        = 18;
             ModifyInviteLinkPasswordAction             modifyInviteLinkPassword        = 19;
             ModifyDescriptionAction                    modifyDescription               = 20;
             ModifyAnnouncementsOnlyAction              modifyAnnouncementsOnly         = 21;
    repeated AddBannedMemberAction                      addBannedMembers                = 22;
    repeated DeleteBannedMemberAction                   deleteBannedMembers             = 23;
    repeated PromotePendingPniAciMemberProfileKeyAction promotePendingPniAciMembers     = 24;
}
*/
typedef ProtoBufParser<protobuffer::optional::BYTES, protobuffer::optional::UINT32,
                       std::vector<AddMemberAction>, std::vector<DeleteMemberAction>,
                       std::vector<ModifyMemberRoleAction>, std::vector<ModifyMemberProfileKeyAction>,
                       std::vector<AddPendingMemberAction>, std::vector<DeletePendingMemberAction>,
                       std::vector<PromotePendingMemberAction>, ModifyTitleAction,
                       ModifyAvatarAction, ModifyDisappearingMessagesTimerAction,
                       ModifyAttributesAccessControlAction, ModifyMembersAccessControlAction,
                       ModifyAddFromInviteLinkAccessControlAction, std::vector<AddRequestingMemberAction>,
                       std::vector<DeleteRequestingMemberAction>, std::vector<PromoteRequestingMemberAction>,
                       ModifyInviteLinkPasswordAction, ModifyDescriptionAction, ModifyAnnouncementsOnlyAction,
                       std::vector<AddBannedMemberAction>, std::vector<DeleteBannedMemberAction>,
                       std::vector<PromotePendingPniAciMemberProfileKeyAction>> Action;

/*
message GroupChange {
  bytes  actions         = 1; // bytes = Action
  bytes  serverSignature = 2;
  uint32 changeEpoch     = 3;
}
*/
typedef ProtoBufParser<Action, protobuffer::optional::BYTES, protobuffer::optional::UINT32> GroupChange;

/*
message GroupContextV2 {
  optional bytes  masterKey   = 1;
  optional uint32 revision    = 2;
  optional bytes  groupChange = 3; // == GroupChange
}
*/
typedef ProtoBufParser<protobuffer::optional::BYTES, protobuffer::optional::UINT32,
                       GroupChange> GroupContextV2;

/*
message DecryptedGroupV2Context {
    signalservice.GroupContextV2 context            = 1;
    DecryptedGroupChange         change             = 2;
    DecryptedGroup               groupState         = 3;
    DecryptedGroup               previousGroupState = 4;
}
*/
typedef ProtoBufParser<GroupContextV2, DecryptedGroupChange,
                       DecryptedGroup, DecryptedGroup> DecryptedGroupV2Context;

#endif
