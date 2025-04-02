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
			AnsiConsole.MarkupLine($"Connections from [lime]Vector[/] clients to be routed to [underline]{GeneralUtilities.GetLocalIPAddress()}:{GeneralUtilities.GenerateRandomPort()}[/].");

			CommandDispatcher dispatch = new();


			while (!dispatch.Exit)
			{
				string input = AnsiConsole.Prompt(new TextPrompt<string>($"({dispatch.StylizedLocation}) >> ")
					.AllowEmpty());
				string[] args = input.Split(' ');

			}
		}
	}
}
