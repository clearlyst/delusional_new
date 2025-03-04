#pragma once
#include <cstdint>
#include "../math/vec3.hpp"

#pragma pack(push, 1)

class i_net_channel {
public:
	uint8_t pad_0x0000[0x17];
	bool should_delete;
	int out_sequence_nr;
	int in_sequence_nr;
	int out_sequence_nr_ack;
	int out_reliable_state;
	int in_reliable_state;
	int choked_packets;
};

class i_client_state
{
public:
	char pad_0000[ 156 ];
	i_net_channel* net_channel;
	uint32_t challenge_count;
	double reconnect_time;
	int32_t retry_count;
	char pad_00A8[ 88 ];
	int32_t signon_state_count;
	char pad_0104[ 8 ];
	float next_cmd_time;
	int32_t server_count;
	uint32_t current_sequence;
	char pad_0118[ 8 ];
	char pad_0120[ 0x4C ];
	int32_t delta_tick;
	bool is_paused;
	char pad_0171[ 3 ];
	int32_t view_entity;
	int32_t player_slot;
	char pad_017C[ 4 ];
	char level_name[ 260 ];
	char level_name_short[ 40 ];
	char pad_02AC[ 92 ];
	int32_t max_clients;
	char pad_030C[ 4083 ];
	uint32_t string_table_container;
	char pad_1303[ 14737 ];
	float last_server_tick_time;
	bool is_in_simulation;
	char pad_4C99[ 3 ];
	uint32_t old_tick_count;
	float tick_remainder;
	float frame_time;
	int32_t last_outgoing_command;
	int32_t choked_commands;
	int32_t last_command_ack;
	int32_t command_ack;
	int32_t sound_sequence;
	char pad_4CBC[ 80 ];
	vec3_t view_angles;


	void full_update( )
	{
		delta_tick = -1;
	}
};

#pragma pack(pop)