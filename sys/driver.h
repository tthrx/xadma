/*
* XDMA Device Driver for Windows
* ===============================
*
* Copyright 2017 Xilinx Inc.
* Copyright 2010-2012 Sidebranch
* Copyright 2010-2012 Leon Woestenberg <leon@sidebranch.com>
*
* Maintainer:
* -----------
* Alexander Hornburg <alexander.hornburg@xilinx.com>
*
* Description:
* ------------
* This is a sample driver for the Xilinx Inc. 'DMA/Bridge Subsystem for PCIe v3.0' (XDMA) IP.
*
* References:
* -----------
*	[1] pg195-pcie-dma.pdf - DMA/Bridge Subsystem for PCI Express v3.0 - Product Guide
*/

#pragma once

#include "xdma.h"
#include "adma.h"

typedef enum {//add by zhuce
	XADMA_TYPE_XDMA = 0,
	XADMA_TYPE_ADMA,
	XADMA_TYPE_XAXIDMA,
	XADMA_TYPE_XAXICDMA,
	XADMA_TYPE_UNKNOWN,
} XADMA_TYPE;

typedef struct DeviceContext_t {
    XDMA_DEVICE xdma;
    WDFQUEUE engineQueue[2][XDMA_MAX_NUM_CHANNELS];
    KEVENT eventSignals[XDMA_MAX_USER_IRQ];

	XADMA_TYPE xadmaType;
	ADMA_DEVICE adma;
}DeviceContext;
WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(DeviceContext, GetDeviceContext)