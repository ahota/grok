/*
*    Copyright (C) 2016 Grok Image Compression Inc.
*
*    This source code is free software: you can redistribute it and/or  modify
*    it under the terms of the GNU Affero General Public License, version 3,
*    as published by the Free Software Foundation.
*
*    This source code is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU Affero General Public License for more details.
*
*    You should have received a copy of the GNU Affero General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*/

#pragma once

#include <string>
#include <thread>
#include <mutex>
#include <vector>
#include <condition_variable>
#include "BlockingQueue.h"
#include <atomic>


class T1Decoder
{
public:
	T1Decoder(uint16_t blockw, uint16_t blockh);
	void decode(std::vector<decodeBlock*>* blocks, int32_t numThreads);

private:

	uint16_t cblk_w, cblk_h;  //nominal dimensions of block

	std::vector<std::thread> decodeWorkers;
	BlockingQueue<decodeBlock*> decodeQueue;

	mutable std::mutex _mutex;
	std::condition_variable _condition;

};