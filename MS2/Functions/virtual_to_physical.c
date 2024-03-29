inline int virtual_to_physical(uint32* page_directory, uint32 virtual_address)
{
		uint32 *page_table = NULL;
		uint32 entry_page_table;
		int frameNum;

		get_page_table(page_directory, virtual_address, &page_table);
		if(page_table != NULL) {
			cprintf("page table found at virtual address: %x\n", page_table);

			entry_page_table = page_table[PTX(virtual_address)];
			frameNum = entry_page_table >> 12;
			return frameNum*4096;
		}
		else {
			cprintf("page table not found\n");
			return -1;
		}

}