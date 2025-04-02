using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Kyanite.Sentinel
{
	internal class CommandDispatcher
	{
		internal bool Exit { get; set; } = false;
		internal string Location { get; set; } = "sentinel";
		internal string StylizedLocation { get; set; } = "[blue]sentinel[/]";
		internal int Lines { get; set; } = 0;
		internal List<ICommand> Commands { get; set; } = new();

		internal async Task Dispatch(string[] args)
		{
			if (args.Length == 0) return;

			foreach (ICommand command in Commands)
			{
				if (command.Command == args[0]) { await command.Execute(args, this); return; }
			}

			return;
		}

		internal void Register(ICommand command)
		{
			Commands.Add(command);
		}
	}
}
