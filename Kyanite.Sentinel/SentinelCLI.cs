using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Spectre.Console;
using Kyanite.Sentinel.Utils;

namespace Kyanite.Sentinel
{
	internal static class SentinelCLI
	{
		public const int LINES = 0;
		public const int VECTOR_CONNECTION_STEPS = 0;

		public static async Task Run()
		{
			AnsiConsole.MarkupLine("Welcome to [blue]Kyanite Sentinel[/]!");
			AnsiConsole.MarkupLine($"To connect from [green]Kyanite Vector[/], use the address [bold]{GeneralUtilities.GetLocalIPAddress()}[/]:{GeneralUtilities.GenerateRandomPort()}");
			

		}
	}
}
