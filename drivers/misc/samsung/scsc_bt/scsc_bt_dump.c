/****************************************************************************
 *
 * Copyright (c) 2014 - 2016 Samsung Electronics Co., Ltd. All rights reserved
 *
 * BT information dumper
 *
 ****************************************************************************/
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/poll.h>
#include <linux/wakelock.h>

#include "scsc_bt_priv.h"
#include "scsc_bt_hci.h"

static char scsc_hci_evt_decode_buffer[512];

const char *scsc_hci_evt_decode_command_code(u16 hci_command_code)
{
	const char *ret = "NA";

	switch (hci_command_code) {
	HCI_CMD_DECODE(HCI_INQUIRY);
	HCI_CMD_DECODE(HCI_INQUIRY_CANCEL);
	HCI_CMD_DECODE(HCI_PERIODIC_INQUIRY_MODE);
	HCI_CMD_DECODE(HCI_EXIT_PERIODIC_INQUIRY_MODE);
	HCI_CMD_DECODE(HCI_CREATE_CONNECTION);
	HCI_CMD_DECODE(HCI_DISCONNECT);
	HCI_CMD_DECODE(HCI_ADD_SCO_CONNECTION);
	HCI_CMD_DECODE(HCI_CREATE_CONNECTION_CANCEL);
	HCI_CMD_DECODE(HCI_ACCEPT_CONNECTION_REQ);
	HCI_CMD_DECODE(HCI_REJECT_CONNECTION_REQ);
	HCI_CMD_DECODE(HCI_LINK_KEY_REQ_REPLY);
	HCI_CMD_DECODE(HCI_LINK_KEY_REQ_NEG_REPLY);
	HCI_CMD_DECODE(HCI_PIN_CODE_REQ_REPLY);
	HCI_CMD_DECODE(HCI_PIN_CODE_REQ_NEG_REPLY);
	HCI_CMD_DECODE(HCI_CHANGE_CONN_PKT_TYPE);
	HCI_CMD_DECODE(HCI_AUTH_REQ);
	HCI_CMD_DECODE(HCI_SET_CONN_ENCRYPTION);
	HCI_CMD_DECODE(HCI_CHANGE_CONN_LINK_KEY);
	HCI_CMD_DECODE(HCI_MASTER_LINK_KEY);
	HCI_CMD_DECODE(HCI_REMOTE_NAME_REQ);
	HCI_CMD_DECODE(HCI_REMOTE_NAME_REQ_CANCEL);
	HCI_CMD_DECODE(HCI_READ_REMOTE_SUPP_FEATURES);
	HCI_CMD_DECODE(HCI_READ_REMOTE_EXT_FEATURES);
	HCI_CMD_DECODE(HCI_READ_REMOTE_VER_INFO);
	HCI_CMD_DECODE(HCI_READ_CLOCK_OFFSET);
	HCI_CMD_DECODE(HCI_READ_LMP_HANDLE);
	HCI_CMD_DECODE(HCI_EXCHANGE_FIXED_INFO);
	HCI_CMD_DECODE(HCI_EXCHANGE_ALIAS_INFO);
	HCI_CMD_DECODE(HCI_PRIVATE_PAIRING_REQ_REPLY);
	HCI_CMD_DECODE(HCI_PRIVATE_PAIRING_REQ_NEG_REPLY);
	HCI_CMD_DECODE(HCI_GENERATED_ALIAS);
	HCI_CMD_DECODE(HCI_ALIAS_ADDRESS_REQ_REPLY);
	HCI_CMD_DECODE(HCI_ALIAS_ADDRESS_REQ_NEG_REPLY);
	HCI_CMD_DECODE(HCI_SETUP_SYNCHRONOUS_CONN);
	HCI_CMD_DECODE(HCI_ACCEPT_SYNCHRONOUS_CONN_REQ);
	HCI_CMD_DECODE(HCI_REJECT_SYNCHRONOUS_CONN_REQ);
	HCI_CMD_DECODE(HCI_IO_CAPABILITY_REQUEST_REPLY);
	HCI_CMD_DECODE(HCI_USER_CONFIRMATION_REQUEST_REPLY);
	HCI_CMD_DECODE(HCI_USER_CONFIRMATION_REQUEST_NEG_REPLY);
	HCI_CMD_DECODE(HCI_USER_PASSKEY_REQUEST_REPLY);
	HCI_CMD_DECODE(HCI_USER_PASSKEY_REQUEST_NEG_REPLY);
	HCI_CMD_DECODE(HCI_REMOTE_OOB_DATA_REQUEST_REPLY);
	HCI_CMD_DECODE(HCI_REMOTE_OOB_DATA_REQUEST_NEG_REPLY);
	HCI_CMD_DECODE(HCI_IO_CAPABILITY_REQUEST_NEG_REPLY);
	HCI_CMD_DECODE(HCI_ENHANCED_SETUP_SYNC_CONN);
	HCI_CMD_DECODE(HCI_ENHANCED_ACCEPT_SYNC_CONN_REQ);
	HCI_CMD_DECODE(HCI_TRUNCATED_PAGE);
	HCI_CMD_DECODE(HCI_TRUNCATED_PAGE_CANCEL);
	HCI_CMD_DECODE(HCI_SET_CSB);
	HCI_CMD_DECODE(HCI_SET_CSB_RECEIVE);
	HCI_CMD_DECODE(HCI_START_SYNCHRONIZATION_TRAIN);
	HCI_CMD_DECODE(HCI_RECEIVE_SYNCHRONIZATION_TRAIN);
	HCI_CMD_DECODE(HCI_REMOTE_OOB_EXTENDED_DATA_REQUEST_REPLY);
	HCI_CMD_DECODE(HCI_HOLD_MODE);
	HCI_CMD_DECODE(HCI_SNIFF_MODE);
	HCI_CMD_DECODE(HCI_EXIT_SNIFF_MODE);
	HCI_CMD_DECODE(HCI_PARK_MODE);
	HCI_CMD_DECODE(HCI_EXIT_PARK_MODE);
	HCI_CMD_DECODE(HCI_QOS_SETUP);
	HCI_CMD_DECODE(HCI_ROLE_DISCOVERY);
	HCI_CMD_DECODE(HCI_SWITCH_ROLE);
	HCI_CMD_DECODE(HCI_READ_LINK_POLICY_SETTINGS);
	HCI_CMD_DECODE(HCI_WRITE_LINK_POLICY_SETTINGS);
	HCI_CMD_DECODE(HCI_READ_DEFAULT_LINK_POLICY_SETTINGS);
	HCI_CMD_DECODE(HCI_WRITE_DEFAULT_LINK_POLICY_SETTINGS);
	HCI_CMD_DECODE(HCI_FLOW_SPEC);
	HCI_CMD_DECODE(HCI_SNIFF_SUB_RATE);
	HCI_CMD_DECODE(HCI_SET_EVENT_MASK);
	HCI_CMD_DECODE(HCI_RESET);
	HCI_CMD_DECODE(HCI_SET_EVENT_FILTER);
	HCI_CMD_DECODE(HCI_FLUSH);
	HCI_CMD_DECODE(HCI_READ_PIN_TYPE);
	HCI_CMD_DECODE(HCI_WRITE_PIN_TYPE);
	HCI_CMD_DECODE(HCI_CREATE_NEW_UNIT_KEY);
	HCI_CMD_DECODE(HCI_READ_STORED_LINK_KEY);
	HCI_CMD_DECODE(HCI_WRITE_STORED_LINK_KEY);
	HCI_CMD_DECODE(HCI_DELETE_STORED_LINK_KEY);
	HCI_CMD_DECODE(HCI_CHANGE_LOCAL_NAME);
	HCI_CMD_DECODE(HCI_READ_LOCAL_NAME);
	HCI_CMD_DECODE(HCI_READ_CONN_ACCEPT_TIMEOUT);
	HCI_CMD_DECODE(HCI_WRITE_CONN_ACCEPT_TIMEOUT);
	HCI_CMD_DECODE(HCI_READ_PAGE_TIMEOUT);
	HCI_CMD_DECODE(HCI_WRITE_PAGE_TIMEOUT);
	HCI_CMD_DECODE(HCI_READ_SCAN_ENABLE);
	HCI_CMD_DECODE(HCI_WRITE_SCAN_ENABLE);
	HCI_CMD_DECODE(HCI_READ_PAGESCAN_ACTIVITY);
	HCI_CMD_DECODE(HCI_WRITE_PAGESCAN_ACTIVITY);
	HCI_CMD_DECODE(HCI_READ_INQUIRYSCAN_ACTIVITY);
	HCI_CMD_DECODE(HCI_WRITE_INQUIRYSCAN_ACTIVITY);
	HCI_CMD_DECODE(HCI_READ_AUTH_ENABLE);
	HCI_CMD_DECODE(HCI_WRITE_AUTH_ENABLE);
	HCI_CMD_DECODE(HCI_READ_ENC_MODE);
	HCI_CMD_DECODE(HCI_WRITE_ENC_MODE);
	HCI_CMD_DECODE(HCI_READ_CLASS_OF_DEVICE);
	HCI_CMD_DECODE(HCI_WRITE_CLASS_OF_DEVICE);
	HCI_CMD_DECODE(HCI_READ_VOICE_SETTING);
	HCI_CMD_DECODE(HCI_WRITE_VOICE_SETTING);
	HCI_CMD_DECODE(HCI_READ_AUTO_FLUSH_TIMEOUT);
	HCI_CMD_DECODE(HCI_WRITE_AUTO_FLUSH_TIMEOUT);
	HCI_CMD_DECODE(HCI_READ_NUM_BCAST_RETXS);
	HCI_CMD_DECODE(HCI_WRITE_NUM_BCAST_RETXS);
	HCI_CMD_DECODE(HCI_READ_HOLD_MODE_ACTIVITY);
	HCI_CMD_DECODE(HCI_WRITE_HOLD_MODE_ACTIVITY);
	HCI_CMD_DECODE(HCI_READ_TX_POWER_LEVEL);
	HCI_CMD_DECODE(HCI_READ_SCO_FLOW_CON_ENABLE);
	HCI_CMD_DECODE(HCI_WRITE_SCO_FLOW_CON_ENABLE);
	HCI_CMD_DECODE(HCI_SET_HCTOHOST_FLOW_CONTROL);
	HCI_CMD_DECODE(HCI_HOST_BUFFER_SIZE);
	HCI_CMD_DECODE(HCI_HOST_NUM_COMPLETED_PACKETS);
	HCI_CMD_DECODE(HCI_READ_LINK_SUPERV_TIMEOUT);
	HCI_CMD_DECODE(HCI_WRITE_LINK_SUPERV_TIMEOUT);
	HCI_CMD_DECODE(HCI_READ_NUM_SUPPORTED_IAC);
	HCI_CMD_DECODE(HCI_READ_CURRENT_IAC_LAP);
	HCI_CMD_DECODE(HCI_WRITE_CURRENT_IAC_LAP);
	HCI_CMD_DECODE(HCI_READ_PAGESCAN_PERIOD_MODE);
	HCI_CMD_DECODE(HCI_WRITE_PAGESCAN_PERIOD_MODE);
	HCI_CMD_DECODE(HCI_READ_PAGESCAN_MODE);
	HCI_CMD_DECODE(HCI_WRITE_PAGESCAN_MODE);
	HCI_CMD_DECODE(HCI_SET_AFH_CHANNEL_CLASS);
	HCI_CMD_DECODE(HCI_READ_INQUIRY_SCAN_TYPE);
	HCI_CMD_DECODE(HCI_WRITE_INQUIRY_SCAN_TYPE);
	HCI_CMD_DECODE(HCI_READ_INQUIRY_MODE);
	HCI_CMD_DECODE(HCI_WRITE_INQUIRY_MODE);
	HCI_CMD_DECODE(HCI_READ_PAGE_SCAN_TYPE);
	HCI_CMD_DECODE(HCI_WRITE_PAGE_SCAN_TYPE);
	HCI_CMD_DECODE(HCI_READ_AFH_CHANNEL_CLASS_M);
	HCI_CMD_DECODE(HCI_WRITE_AFH_CHANNEL_CLASS_M);
	HCI_CMD_DECODE(HCI_READ_ANON_MODE);
	HCI_CMD_DECODE(HCI_WRITE_ANON_MODE);
	HCI_CMD_DECODE(HCI_READ_ALIAS_AUTH_ENABLE);
	HCI_CMD_DECODE(HCI_WRITE_ALIAS_AUTH_ENABLE);
	HCI_CMD_DECODE(HCI_READ_ANON_ADDR_CHANGE_PARAMS);
	HCI_CMD_DECODE(HCI_WRITE_ANON_ADDR_CHANGE_PARAMS);
	HCI_CMD_DECODE(HCI_RESET_FIXED_ADDRESS_ATTEMPTS_COUNTER);
	HCI_CMD_DECODE(HCI_READ_EXTENDED_INQUIRY_RESPONSE_DATA);
	HCI_CMD_DECODE(HCI_WRITE_EXTENDED_INQUIRY_RESPONSE_DATA);
	HCI_CMD_DECODE(HCI_REFRESH_ENCRYPTION_KEY);
	HCI_CMD_DECODE(HCI_READ_SIMPLE_PAIRING_MODE);
	HCI_CMD_DECODE(HCI_WRITE_SIMPLE_PAIRING_MODE);
	HCI_CMD_DECODE(HCI_READ_LOCAL_OOB_DATA);
	HCI_CMD_DECODE(HCI_READ_INQUIRY_RESPONSE_TX_POWER_LEVEL);
	HCI_CMD_DECODE(HCI_WRITE_INQUIRY_TRANSMIT_POWER_LEVEL);
	HCI_CMD_DECODE(HCI_ENHANCED_FLUSH);
	HCI_CMD_DECODE(HCI_SEND_KEYPRESS_NOTIFICATION);
	HCI_CMD_DECODE(HCI_SET_EVENT_MASK_PAGE_2);
	HCI_CMD_DECODE(HCI_READ_ENH_TX_POWER_LEVEL);
	HCI_CMD_DECODE(HCI_READ_LE_HOST_SUPPORT);
	HCI_CMD_DECODE(HCI_WRITE_LE_HOST_SUPPORT);
	HCI_CMD_DECODE(HCI_SET_RESERVED_LT_ADDR);
	HCI_CMD_DECODE(HCI_DELETE_RESERVED_LT_ADDR);
	HCI_CMD_DECODE(HCI_SET_CSB_DATA);
	HCI_CMD_DECODE(HCI_READ_SYNCHRONIZATION_TRAIN_PARAMS);
	HCI_CMD_DECODE(HCI_WRITE_SYNCHRONIZATION_TRAIN_PARAMS);
	HCI_CMD_DECODE(HCI_READ_SECURE_CONNECTIONS_HOST_SUPPORT);
	HCI_CMD_DECODE(HCI_WRITE_SECURE_CONNECTIONS_HOST_SUPPORT);
	HCI_CMD_DECODE(HCI_READ_AUTHENTICATED_PAYLOAD_TIMEOUT);
	HCI_CMD_DECODE(HCI_WRITE_AUTHENTICATED_PAYLOAD_TIMEOUT);
	HCI_CMD_DECODE(HCI_READ_LOCAL_OOB_EXTENDED_DATA);
	HCI_CMD_DECODE(HCI_READ_LOCAL_VER_INFO);
	HCI_CMD_DECODE(HCI_READ_LOCAL_SUPP_COMMANDS);
	HCI_CMD_DECODE(HCI_READ_LOCAL_SUPP_FEATURES);
	HCI_CMD_DECODE(HCI_READ_LOCAL_EXT_FEATURES);
	HCI_CMD_DECODE(HCI_READ_BUFFER_SIZE);
	HCI_CMD_DECODE(HCI_READ_COUNTRY_CODE);
	HCI_CMD_DECODE(HCI_READ_BD_ADDR);
	HCI_CMD_DECODE(HCI_READ_LOCAL_SUPP_CODECS);
	HCI_CMD_DECODE(HCI_READ_FAILED_CONTACT_COUNT);
	HCI_CMD_DECODE(HCI_RESET_FAILED_CONTACT_COUNT);
	HCI_CMD_DECODE(HCI_GET_LINK_QUALITY);
	HCI_CMD_DECODE(HCI_READ_RSSI);
	HCI_CMD_DECODE(HCI_READ_AFH_CHANNEL_MAP);
	HCI_CMD_DECODE(HCI_READ_CLOCK);
	HCI_CMD_DECODE(HCI_READ_ENCRYPTION_KEY_SIZE);
	HCI_CMD_DECODE(HCI_SET_TRIGGERED_CLOCK_CAPTURE);
	HCI_CMD_DECODE(HCI_READ_LOOPBACK_MODE);
	HCI_CMD_DECODE(HCI_WRITE_LOOPBACK_MODE);
	HCI_CMD_DECODE(HCI_ENABLE_DUT_MODE);
	HCI_CMD_DECODE(HCI_WRITE_SIMPLE_PAIRING_DEBUG_MODE);
	HCI_CMD_DECODE(HCI_WRITE_SECURE_CONNECTIONS_TEST_MODE);
	HCI_CMD_DECODE(HCI_ULP_SET_EVENT_MASK);
	HCI_CMD_DECODE(HCI_ULP_READ_BUFFER_SIZE);
	HCI_CMD_DECODE(HCI_ULP_READ_LOCAL_SUPPORTED_FEATURES);
	HCI_CMD_DECODE(HCI_ULP_SET_RANDOM_ADDRESS);
	HCI_CMD_DECODE(HCI_ULP_SET_ADVERTISING_PARAMETERS);
	HCI_CMD_DECODE(HCI_ULP_READ_ADVERTISING_CHANNEL_TX_POWER);
	HCI_CMD_DECODE(HCI_ULP_SET_ADVERTISING_DATA);
	HCI_CMD_DECODE(HCI_ULP_SET_SCAN_RESPONSE_DATA);
	HCI_CMD_DECODE(HCI_ULP_SET_ADVERTISE_ENABLE);
	HCI_CMD_DECODE(HCI_ULP_SET_SCAN_PARAMETERS);
	HCI_CMD_DECODE(HCI_ULP_SET_SCAN_ENABLE);
	HCI_CMD_DECODE(HCI_ULP_CREATE_CONNECTION);
	HCI_CMD_DECODE(HCI_ULP_CREATE_CONNECTION_CANCEL);
	HCI_CMD_DECODE(HCI_ULP_READ_WHITE_LIST_SIZE);
	HCI_CMD_DECODE(HCI_ULP_CLEAR_WHITE_LIST);
	HCI_CMD_DECODE(HCI_ULP_ADD_DEVICE_TO_WHITE_LIST);
	HCI_CMD_DECODE(HCI_ULP_REMOVE_DEVICE_FROM_WHITE_LIST);
	HCI_CMD_DECODE(HCI_ULP_CONNECTION_UPDATE);
	HCI_CMD_DECODE(HCI_ULP_SET_HOST_CHANNEL_CLASSIFICATION);
	HCI_CMD_DECODE(HCI_ULP_READ_CHANNEL_MAP);
	HCI_CMD_DECODE(HCI_ULP_READ_REMOTE_USED_FEATURES);
	HCI_CMD_DECODE(HCI_ULP_ENCRYPT);
	HCI_CMD_DECODE(HCI_ULP_RAND);
	HCI_CMD_DECODE(HCI_ULP_START_ENCRYPTION);
	HCI_CMD_DECODE(HCI_ULP_LONG_TERM_KEY_REQUEST_REPLY);
	HCI_CMD_DECODE(HCI_ULP_LONG_TERM_KEY_REQUEST_NEGATIVE_REPLY);
	HCI_CMD_DECODE(HCI_ULP_READ_SUPPORTED_STATES);
	HCI_CMD_DECODE(HCI_ULP_RECEIVER_TEST);
	HCI_CMD_DECODE(HCI_ULP_TRANSMITTER_TEST);
	HCI_CMD_DECODE(HCI_ULP_TEST_END);
	HCI_CMD_DECODE(HCI_ULP_REMOTE_CONNECTION_PARAMETER_REQUEST_REPLY);
	HCI_CMD_DECODE(HCI_ULP_REMOTE_CONNECTION_PARAMETER_REQUEST_NEGATIVE_REPLY);
	HCI_CMD_DECODE(HCI_ULP_SET_DATA_LENGTH);
	HCI_CMD_DECODE(HCI_ULP_READ_SUGGESTED_DEFAULT_DATA_LENGTH);
	HCI_CMD_DECODE(HCI_ULP_WRITE_SUGGESTED_DEFAULT_DATA_LENGTH);
	HCI_CMD_DECODE(HCI_ULP_READ_LOCAL_P256_PUBLIC_KEY);
	HCI_CMD_DECODE(HCI_ULP_GENERATE_DHKEY);
	HCI_CMD_DECODE(HCI_ULP_ADD_DEVICE_TO_RESOLVING_LIST);
	HCI_CMD_DECODE(HCI_ULP_REMOVE_DEVICE_FROM_RESOLVING_LIST);
	HCI_CMD_DECODE(HCI_ULP_CLEAR_RESOLVING_LIST);
	HCI_CMD_DECODE(HCI_ULP_READ_RESOLVING_LIST_SIZE);
	HCI_CMD_DECODE(HCI_ULP_READ_PEER_RESOLVABLE_ADDRESS);
	HCI_CMD_DECODE(HCI_ULP_READ_LOCAL_RESOLVABLE_ADDRESS);
	HCI_CMD_DECODE(HCI_ULP_SET_ADDRESS_RESOLUTION_ENABLE);
	HCI_CMD_DECODE(HCI_ULP_SET_RANDOM_PRIVATE_ADDRESS_TIMEOUT);
	HCI_CMD_DECODE(HCI_ULP_READ_MAXIMUM_DATA_LENGTH);
	HCI_CMD_DECODE(HCI_ULP_READ_PHY);
	HCI_CMD_DECODE(HCI_ULP_SET_DEFAULT_PHY);
	HCI_CMD_DECODE(HCI_ULP_SET_PHY);
	HCI_CMD_DECODE(HCI_ULP_ENHANCED_RECEIVER_TEST);
	HCI_CMD_DECODE(HCI_ULP_ENHANCED_TRANSMITTER_TEST);
	}

	return ret;
}

static const char *scsc_bt_dump_hci_command(struct BSMHCP_TD_CONTROL *td_info)
{
	return td_info->length ?
	       scsc_hci_evt_decode_command_code(*((u16 *) &td_info->data[0])) :
	       "[empty]";
}

const char *scsc_hci_evt_decode_event_code(u8 *data)
{
	const char *ret = "NA";
	u8 hci_event_code   = data[0];
	u8 hci_ulp_sub_code = data[2];

	switch (hci_event_code) {
	HCI_EV_DECODE(HCI_EV_INQUIRY_COMPLETE);
	HCI_EV_DECODE(HCI_EV_INQUIRY_RESULT);
	HCI_EV_DECODE(HCI_EV_CONN_COMPLETE);
	HCI_EV_DECODE(HCI_EV_CONN_REQUEST);
	HCI_EV_DECODE(HCI_EV_DISCONNECT_COMPLETE);
	HCI_EV_DECODE(HCI_EV_AUTH_COMPLETE);
	HCI_EV_DECODE(HCI_EV_REMOTE_NAME_REQ_COMPLETE);
	HCI_EV_DECODE(HCI_EV_ENCRYPTION_CHANGE);
	HCI_EV_DECODE(HCI_EV_CHANGE_CONN_LINK_KEY_COMPLETE);
	HCI_EV_DECODE(HCI_EV_MASTER_LINK_KEY_COMPLETE);
	HCI_EV_DECODE(HCI_EV_READ_REM_SUPP_FEATURES_COMPLETE);
	HCI_EV_DECODE(HCI_EV_READ_REMOTE_VER_INFO_COMPLETE);
	HCI_EV_DECODE(HCI_EV_QOS_SETUP_COMPLETE);
	HCI_EV_DECODE(HCI_EV_HARDWARE_ERROR);
	HCI_EV_DECODE(HCI_EV_FLUSH_OCCURRED);
	HCI_EV_DECODE(HCI_EV_ROLE_CHANGE);
	HCI_EV_DECODE(HCI_EV_NUMBER_COMPLETED_PKTS);
	HCI_EV_DECODE(HCI_EV_MODE_CHANGE);
	HCI_EV_DECODE(HCI_EV_RETURN_LINK_KEYS);
	HCI_EV_DECODE(HCI_EV_PIN_CODE_REQ);
	HCI_EV_DECODE(HCI_EV_LINK_KEY_REQ);
	HCI_EV_DECODE(HCI_EV_LINK_KEY_NOTIFICATION);
	HCI_EV_DECODE(HCI_EV_LOOPBACK_COMMAND);
	HCI_EV_DECODE(HCI_EV_DATA_BUFFER_OVERFLOW);
	HCI_EV_DECODE(HCI_EV_MAX_SLOTS_CHANGE);
	HCI_EV_DECODE(HCI_EV_READ_CLOCK_OFFSET_COMPLETE);
	HCI_EV_DECODE(HCI_EV_CONN_PACKET_TYPE_CHANGED);
	HCI_EV_DECODE(HCI_EV_QOS_VIOLATION);
	HCI_EV_DECODE(HCI_EV_PAGE_SCAN_MODE_CHANGE);
	HCI_EV_DECODE(HCI_EV_PAGE_SCAN_REP_MODE_CHANGE);
	HCI_EV_DECODE(HCI_EV_FLOW_SPEC_COMPLETE);
	HCI_EV_DECODE(HCI_EV_INQUIRY_RESULT_WITH_RSSI);
	HCI_EV_DECODE(HCI_EV_READ_REM_EXT_FEATURES_COMPLETE);
	HCI_EV_DECODE(HCI_EV_FIXED_ADDRESS);
	HCI_EV_DECODE(HCI_EV_ALIAS_ADDRESS);
	HCI_EV_DECODE(HCI_EV_GENERATE_ALIAS_REQ);
	HCI_EV_DECODE(HCI_EV_ACTIVE_ADDRESS);
	HCI_EV_DECODE(HCI_EV_ALLOW_PRIVATE_PAIRING);
	HCI_EV_DECODE(HCI_EV_ALIAS_ADDRESS_REQ);
	HCI_EV_DECODE(HCI_EV_ALIAS_NOT_RECOGNISED);
	HCI_EV_DECODE(HCI_EV_FIXED_ADDRESS_ATTEMPT);
	HCI_EV_DECODE(HCI_EV_SYNC_CONN_COMPLETE);
	HCI_EV_DECODE(HCI_EV_SYNC_CONN_CHANGED);
	HCI_EV_DECODE(HCI_EV_SNIFF_SUB_RATE);
	HCI_EV_DECODE(HCI_EV_EXTENDED_INQUIRY_RESULT);
	HCI_EV_DECODE(HCI_EV_ENCRYPTION_KEY_REFRESH_COMPLETE);
	HCI_EV_DECODE(HCI_EV_IO_CAPABILITY_REQUEST);
	HCI_EV_DECODE(HCI_EV_IO_CAPABILITY_RESPONSE);
	HCI_EV_DECODE(HCI_EV_USER_CONFIRMATION_REQUEST);
	HCI_EV_DECODE(HCI_EV_USER_PASSKEY_REQUEST);
	HCI_EV_DECODE(HCI_EV_REMOTE_OOB_DATA_REQUEST);
	HCI_EV_DECODE(HCI_EV_SIMPLE_PAIRING_COMPLETE);
	HCI_EV_DECODE(HCI_EV_LST_CHANGE);
	HCI_EV_DECODE(HCI_EV_ENHANCED_FLUSH_COMPLETE);
	HCI_EV_DECODE(HCI_EV_USER_PASSKEY_NOTIFICATION);
	HCI_EV_DECODE(HCI_EV_KEYPRESS_NOTIFICATION);
	HCI_EV_DECODE(HCI_EV_REM_HOST_SUPPORTED_FEATURES);
	HCI_EV_DECODE(HCI_EV_TRIGGERED_CLOCK_CAPTURE);
	HCI_EV_DECODE(HCI_EV_SYNCHRONIZATION_TRAIN_COMPLETE);
	HCI_EV_DECODE(HCI_EV_SYNCHRONIZATION_TRAIN_RECEIVED);
	HCI_EV_DECODE(HCI_EV_CSB_RECEIVE);
	HCI_EV_DECODE(HCI_EV_CSB_TIMEOUT);
	HCI_EV_DECODE(HCI_EV_TRUNCATED_PAGE_COMPLETE);
	HCI_EV_DECODE(HCI_EV_SLAVE_PAGE_RESPONSE_TIMEOUT);
	HCI_EV_DECODE(HCI_EV_CSB_CHANNEL_MAP_CHANGE);
	HCI_EV_DECODE(HCI_EV_INQUIRY_RESPONSE_NOTIFICATION);
	HCI_EV_DECODE(HCI_EV_AUTHENTICATED_PAYLOAD_TIMEOUT_EXPIRED);
	case HCI_EV_COMMAND_COMPLETE:
	{
		u16 op_code = *((u16 *) &data[3]);

		snprintf(scsc_hci_evt_decode_buffer,
			 sizeof(scsc_hci_evt_decode_buffer),
			 "HCI_EV_COMMAND_COMPLETE[Opcode=%s (0x%04x)]",
			 scsc_hci_evt_decode_command_code(op_code),
			 op_code);
		ret = scsc_hci_evt_decode_buffer;
		break;
	}
	case HCI_EV_COMMAND_STATUS:
	{
		u8 status  = data[3];
		u16 op_code = *((u16 *) &data[4]);

		snprintf(scsc_hci_evt_decode_buffer,
			 sizeof(scsc_hci_evt_decode_buffer),
			 "HCI_EV_COMMAND_STATUS[Opcode:%s (0x%04x), Status: %u]",
			 scsc_hci_evt_decode_command_code(op_code),
			 op_code,
			 status);
		ret = scsc_hci_evt_decode_buffer;

		break;
	}
	case HCI_EV_ULP:
	{
		switch (hci_ulp_sub_code) {
		HCI_EV_DECODE(HCI_EV_ULP_CONNECTION_COMPLETE);
		HCI_EV_DECODE(HCI_EV_ULP_ADVERTISING_REPORT);
		HCI_EV_DECODE(HCI_EV_ULP_CONNECTION_UPDATE_COMPLETE);
		HCI_EV_DECODE(HCI_EV_ULP_READ_REMOTE_USED_FEATURES_COMPLETE);
		HCI_EV_DECODE(HCI_EV_ULP_LONG_TERM_KEY_REQUEST);
		HCI_EV_DECODE(HCI_EV_ULP_REMOTE_CONNECTION_PARAMETER_REQUEST);
		HCI_EV_DECODE(HCI_EV_ULP_DATA_LENGTH_CHANGE);
		HCI_EV_DECODE(HCI_EV_ULP_READ_LOCAL_P256_PUB_KEY_COMPLETE);
		HCI_EV_DECODE(HCI_EV_ULP_GENERATE_DHKEY_COMPLETE);
		HCI_EV_DECODE(HCI_EV_ULP_ENHANCED_CONNECTION_COMPLETE);
		HCI_EV_DECODE(HCI_EV_ULP_DIRECT_ADVERTISING_REPORT);
		HCI_EV_DECODE(HCI_EV_ULP_PHY_UPDATE_COMPLETE);
		HCI_EV_DECODE(HCI_EV_ULP_USED_CHANNEL_SELECTION);
		}
		break;
	}
	}

	return ret;
}

static const char *scsc_bt_dump_hci_event(struct BSMHCP_TD_HCI_EVT *td_info)
{
	return td_info->length ?
	       scsc_hci_evt_decode_event_code(td_info->data) :
	       "[empty]";
}

void scsc_bt_dump_driver_state(void)
{
	if (bt_service.bsmhcp_protocol) {
		u32 index;
		u32 readidx;
		u32 writeidx;

		pr_info("scsc_bt_dump_driver_state: Bluetooth Shared Memory Host Controller Protocol\n");
		pr_info("scsc_bt_dump_driver_state:   transfer ring       read_idx  write_idx\n");
		pr_info("scsc_bt_dump_driver_state:   ---------------------------------------\n");
		pr_info("scsc_bt_dump_driver_state:   hci_cmd                  %3u        %3u\n",
			bt_service.bsmhcp_protocol->header.mailbox_hci_cmd_read,
			bt_service.bsmhcp_protocol->header.mailbox_hci_cmd_write);
		pr_info("scsc_bt_dump_driver_state:   hci_evt                  %3u        %3u\n",
			bt_service.bsmhcp_protocol->header.mailbox_hci_evt_read,
			bt_service.bsmhcp_protocol->header.mailbox_hci_evt_write);
		pr_info("scsc_bt_dump_driver_state:   acl_tx                   %3u        %3u\n",
			bt_service.bsmhcp_protocol->header.mailbox_acl_tx_read,
			bt_service.bsmhcp_protocol->header.mailbox_acl_tx_write);
		pr_info("scsc_bt_dump_driver_state:   acl_rx                   %3u        %3u\n",
			bt_service.bsmhcp_protocol->header.mailbox_acl_rx_read,
			bt_service.bsmhcp_protocol->header.mailbox_acl_rx_write);
		pr_info("scsc_bt_dump_driver_state:   acl_free                 %3u        %3u\n",
			bt_service.bsmhcp_protocol->header.mailbox_acl_free_read,
			bt_service.bsmhcp_protocol->header.mailbox_acl_free_write);
		pr_info("scsc_bt_dump_driver_state:   ---------------------------------------\n");
		pr_info("scsc_bt_dump_driver_state:   mxlog_filter     = 0x%08x\n",
			bt_service.bsmhcp_protocol->header.mxlog_filter);
		pr_info("scsc_bt_dump_driver_state:   firmware_control = 0x%08x\n",
			bt_service.bsmhcp_protocol->header.firmware_control);
		pr_info("scsc_bt_dump_driver_state:   system_state     = %s\n",
			bt_service.bsmhcp_protocol->header.controller_flags == 0 ? "STOPPED" :
			(bt_service.bsmhcp_protocol->header.controller_flags == 1 ? "STARTED" : "RUNNING"));
		pr_info("scsc_bt_dump_driver_state:   HCI commands:\n");
		pr_info("scsc_bt_dump_driver_state:     ptr  index  len  details\n");
		pr_info("scsc_bt_dump_driver_state:     -------------------------------------------------------------\n");

		readidx  = bt_service.bsmhcp_protocol->header.mailbox_hci_cmd_read;
		writeidx = bt_service.bsmhcp_protocol->header.mailbox_hci_cmd_write;
		for (index = 0; index < BSMHCP_TRANSFER_RING_CMD_SIZE; index++) {
			uint32_t write = writeidx >= index ? writeidx - index : BSMHCP_TRANSFER_RING_CMD_SIZE - index + writeidx;
			struct BSMHCP_TD_CONTROL *td_info =
				&bt_service.bsmhcp_protocol->hci_cmd_transfer_ring[write];

			pr_info("scsc_bt_dump_driver_state:     %c %c  %3u    %3u  %s\n",
				write == writeidx ? 'W' : ' ',
				write == readidx ? 'R' : ' ',
				write,
				td_info->length,
				scsc_bt_dump_hci_command(td_info));
		}
		pr_info("scsc_bt_dump_driver_state:     -------------------------------------------------------------\n");

		pr_info("scsc_bt_dump_driver_state:   HCI events:\n");
		pr_info("scsc_bt_dump_driver_state:     ptr  index  len  hci_handle  event  details\n");
		pr_info("scsc_bt_dump_driver_state:     -------------------------------------------------------------\n");

		readidx  = bt_service.bsmhcp_protocol->header.mailbox_hci_evt_read;
		writeidx = bt_service.bsmhcp_protocol->header.mailbox_hci_evt_write;
		for (index = 0; index < BSMHCP_TRANSFER_RING_EVT_SIZE; index++) {
			uint32_t write = writeidx >= index ? writeidx - index : BSMHCP_TRANSFER_RING_EVT_SIZE - index + writeidx;
			struct BSMHCP_TD_HCI_EVT *td_info =
				&bt_service.bsmhcp_protocol->hci_evt_transfer_ring[write];

			pr_info("scsc_bt_dump_driver_state:     %c %c    %3u  %3u       0x%03x     %2u  %s\n",
				write == writeidx ? 'W' : ' ',
				write == readidx ? 'R' : ' ',
				write,
				td_info->length,
				td_info->hci_connection_handle,
				td_info->event_type,
				scsc_bt_dump_hci_event(td_info));
		}
		pr_info("scsc_bt_dump_driver_state:     -------------------------------------------------------------\n");

		pr_info("scsc_bt_dump_driver_state:   ACL to AIR:\n");
		pr_info("scsc_bt_dump_driver_state:     ptr  index  len  idx  start  flush  broadcast  hci_handle     cid\n");
		pr_info("scsc_bt_dump_driver_state:     -----------------------------------------------------------------\n");

		readidx  = bt_service.bsmhcp_protocol->header.mailbox_acl_tx_read;
		writeidx = bt_service.bsmhcp_protocol->header.mailbox_acl_tx_write;
		for (index = 0; index < BSMHCP_TRANSFER_RING_ACL_SIZE; index++) {
			uint32_t write = writeidx >= index ? writeidx - index : BSMHCP_TRANSFER_RING_ACL_SIZE - index + writeidx;
			struct BSMHCP_TD_ACL_TX_DATA *td_info =
				&bt_service.bsmhcp_protocol->acl_tx_data_transfer_ring[write];
			u8 pb = td_info->flags & BSMHCP_ACL_PB_FLAG_MASK;
			u8 bc = td_info->flags & BSMHCP_ACL_BC_FLAG_BCAST_MASK;

			pr_info("scsc_bt_dump_driver_state:     %c %c    %3u  %3u  %3u    %c      %c        %c           0x%03x  0x%04x\n",
				write == writeidx ? 'W' : ' ',
				write == readidx ? 'R' : ' ',
				write,
				td_info->length,
				td_info->buffer_index,
				pb == BSMHCP_ACL_PB_FLAG_CONT ? 'N' : 'Y',
				pb == BSMHCP_ACL_PB_FLAG_START_FLUSH ? 'Y' : 'N',
				bc == BSMHCP_ACL_BC_FLAG_BCAST_NON ? 'N' : 'Y',
				td_info->hci_connection_handle,
				td_info->l2cap_cid);

		}
		pr_info("scsc_bt_dump_driver_state:     -----------------------------------------------------------------\n");

		pr_info("scsc_bt_dump_driver_state:   ACL from AIR:\n");
		pr_info("scsc_bt_dump_driver_state:     ptr  index  len  start  flush  hci_handle  dis\n");
		pr_info("scsc_bt_dump_driver_state:     ----------------------------------------------\n");

		readidx  = bt_service.bsmhcp_protocol->header.mailbox_acl_rx_read;
		writeidx = bt_service.bsmhcp_protocol->header.mailbox_acl_rx_write;
		for (index = 0; index < BSMHCP_TRANSFER_RING_ACL_SIZE; index++) {
			uint32_t write = writeidx >= index ? writeidx - index : BSMHCP_TRANSFER_RING_ACL_SIZE - index + writeidx;
			struct BSMHCP_TD_ACL_RX *td_info =
				&bt_service.bsmhcp_protocol->acl_rx_transfer_ring[write];
			u8 pb = (td_info->packet_boundary << 4) & BSMHCP_ACL_PB_FLAG_MASK;

			pr_info("scsc_bt_dump_driver_state:     %c %c    %3u  %3u    %c      %c         0x%03x   %c\n",
				write == writeidx ? 'W' : ' ',
				write == readidx ? 'R' : ' ',
				write,
				td_info->length,
				pb == BSMHCP_ACL_PB_FLAG_CONT ? 'N' : 'Y',
				td_info->broadcast_flag ? 'Y' : 'N',
				td_info->hci_connection_handle,
				td_info->disconnected ? 'Y' : 'N');

		}
		pr_info("scsc_bt_dump_driver_state:     ----------------------------------------------\n");
	}
}

